#include <lexer.hpp>

Lexer::Lexer(const std::string& aFileName, const std::string& aSource) :
  mSource(aSource),
  mIndex(0),
  mFileName(aFileName),
  mLine(1),
  mCursor(1) {}

std::string Lexer::ReadCharacter(bool aUpdateIndex) {
  std::string tResult = "";
  int tLength = 0;

  if (mIndex < mSource.size())
    tLength = GetUTF8SequenceLength(&(mSource[mIndex]));

  assert(tLength >= 0);

  for (int i = 0; i < tLength; i++, mIndex++)
    tResult += mSource[mIndex];

  if (!aUpdateIndex) {
    mIndex -= tLength;
  } else {
    mCursor += 1;
  }

  return tResult;
}

std::string Lexer::PeekCharacter() {
  return ReadCharacter(false);
}

void Lexer::ReadComment() {
  std::string tCharacter = ReadCharacter();
  std::string tPeekCharacter = PeekCharacter();
  if (tPeekCharacter.size() > 0) {
    if (tPeekCharacter[0] == '/') { // line comment
      ReadCharacter();
      while(tPeekCharacter[0] != 0x0A && tPeekCharacter[0] != EOF
        && mIndex < mSource.size())
        tPeekCharacter = ReadCharacter();

      if (tPeekCharacter[0] != EOF) {
        mLine += 1;
        mCursor = 1;
      }
    } else if (tPeekCharacter[0] == '*') { // block comment
      while(true) {
        tPeekCharacter = PeekCharacter();
        if (tPeekCharacter[0] == EOF) {
          Token tToken;
          tToken.mType = TokenType::ILLEGAL;
          tToken.mLiteral = tPeekCharacter;
          tToken.mFileName = mFileName; 
          tToken.mLine = mLine;
          tToken.mCursor = mCursor;
          // TODO: error unterminated block comment
        }

        if (tPeekCharacter[0] == 0x0A) {
          ReadCharacter();
          mLine += 1; 
          mCursor = 1;
          continue;
        }

        if (tPeekCharacter[0] == '*') {
          ReadCharacter();
          tPeekCharacter = PeekCharacter();

          if (tPeekCharacter[0] == EOF) {
            Token tToken;
            tToken.mType = TokenType::ILLEGAL;
            tToken.mLiteral = tPeekCharacter;
            tToken.mFileName = mFileName; 
            tToken.mLine = mLine;
            tToken.mCursor = mCursor;
            // TODO: error unterminated block comment
          }

          if (tPeekCharacter[0] == '/') {
            ReadCharacter();
            return;
          }
        }
        ReadCharacter();
      }
    } else {
      Token tToken;
      tToken.mType = TokenType::SLASH;
      tToken.mLiteral = tCharacter;
      tToken.mFileName = mFileName; 
      tToken.mLine = mLine;
      tToken.mCursor = mCursor - 1;
      mTokens.push_back(tToken);
    }
  } else {
    Token tToken;
    tToken.mType = TokenType::SLASH;
    tToken.mLiteral = tCharacter;
    tToken.mFileName = mFileName; 
    tToken.mLine = mLine;
    tToken.mCursor = mCursor - 1;
    mTokens.push_back(tToken);
  }
}

void Lexer::ReadNumber(const std::string& aCharacter) {
  Token tToken;
  tToken.mFileName = mFileName;
  tToken.mLine = mLine;
  tToken.mCursor = mCursor;
  tToken.mType = TokenType::INTEGER;
  tToken.mLiteral = aCharacter;

  std::string tCharacter = ReadCharacter();
  while(true) {
    tCharacter = PeekCharacter();
    if (tCharacter.size() == 1 && 
       (tCharacter[0] == '.' || isdigit(tCharacter[0]))) {
      tCharacter = ReadCharacter();
      tToken.mLiteral += tCharacter;
      continue;
    }
    break;
  }
  if (tToken.mLiteral.find(".") != std::string::npos) {
    tToken.mType = TokenType::DOUBLE;
  }
  mTokens.push_back(tToken);
}

void Lexer::ReadWhitespace() {
  ReadCharacter();
  while(true) {
    std::string tCharacter = PeekCharacter();
    if (tCharacter[0] == ' ' || tCharacter[0] == 0x08 ||
        tCharacter[0] == 0x09 || tCharacter[0] == 0x0D) {
      tCharacter = ReadCharacter();
    } else return;
  }
}

void Lexer::Tokenize() {
  for (mIndex = 0; mIndex < mSource.size();) {
    if (IsUTF8(mSource[mIndex])) {
      std::string tCharacter = PeekCharacter();

      if (tCharacter[0] == '/') { // comment
        ReadComment();
      } else if (isdigit(tCharacter[0])) { // number
        ReadNumber(tCharacter);
      } else if (tCharacter[0] == ' ' || // whitespace
                 tCharacter[0] == 0x08 ||
                 tCharacter[0] == 0x09 || 
                 tCharacter[0] == 0x0D) {
        ReadWhitespace();
      }

      if (tCharacter[0] == '\n') {
        mLine += 1;
        ReadCharacter();
        mCursor = 1;
      }

    }
  }

  for (auto& tToken : mTokens)
    std::cout << "[LEXER] " << tToken.mLine << " " 
      << tToken.mCursor << " " << tToken.mLiteral << std::endl;
}