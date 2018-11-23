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

  for (int i = 0; i < tLength; i++)
    tResult += mSource[mIndex + i];

  if (aUpdateIndex) {
    mIndex += mIndex + tLength;
    mCursor += 1;
  }

  return tResult;
}

std::string Lexer::PeekCharacter() {
  return ReadCharacter(false);
}

void Lexer::ReadComment() {
  std::string tCharacter = ReadCharacter();
  assert(tCharacter == "/");
  std::string tPeekCharacter = PeekCharacter();
  if (tPeekCharacter.size() > 0) {
    if (tPeekCharacter[0] == '/') { // line comment
      ReadCharacter();
      while(tPeekCharacter[0] != 0x0A && mIndex < mSource.size())
        tPeekCharacter = ReadCharacter();

      if (tPeekCharacter[0] != EOF) {
        mLine += 1;
        mCursor = 1;
      }
    } else if (tPeekCharacter[0] == '*') { // block comment
      while(true) {
        tPeekCharacter = PeekCharacter();
        if (tPeekCharacter[0] == EOF) {
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
  }
}