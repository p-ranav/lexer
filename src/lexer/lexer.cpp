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
      std::string tPeekCharacter = PeekCharacter();
      if (tPeekCharacter == "=") {
        ReadCharacter();
        tToken.mLiteral = "/=";
        tToken.mType = TokenType::SLASH_EQUAL;
      }
      mTokens.push_back(tToken);
    }
  } else {
    Token tToken;
    tToken.mType = TokenType::SLASH;
    tToken.mLiteral = tCharacter;
    tToken.mFileName = mFileName; 
    tToken.mLine = mLine;
    tToken.mCursor = mCursor - 1;
    std::string tPeekCharacter = PeekCharacter();
    if (tPeekCharacter == "=") {
      ReadCharacter();
      tToken.mLiteral = "/=";
      tToken.mType = TokenType::SLASH_EQUAL;
    }
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

void Lexer::ReadString() {
  Token tToken;
  tToken.mFileName = mFileName;
  tToken.mLine = mLine;
  tToken.mCursor = mCursor;
  tToken.mType = TokenType::STRING;
  tToken.mLiteral = "";

  std::string tCharacter = ReadCharacter();

  while(true) {
    tCharacter = PeekCharacter();
    if (tCharacter[0] == '\\') {
      tCharacter = ReadCharacter();
      if (tCharacter[0] == '\"' || tCharacter[0] == '\\') {
        tCharacter = ReadCharacter();
        if (tCharacter == "n") {
          tToken.mLiteral += '\n';
        } else {
          // TODO: unrecognized escape sequence
          tToken.mLiteral += tCharacter;
        }
        continue;
      } else if (tCharacter[0] == 'n') {
        tCharacter = ReadCharacter();
        tToken.mLiteral += '\n';
      }

      if (tCharacter[0] == 0x0A || tCharacter[0] == EOF) {
        // TODO: report unterminated string literal
      }

      tToken.mLiteral += tCharacter;
      continue;
    }

    if (tCharacter[0] != '\"' && tCharacter[0] != EOF) {
      tCharacter = ReadCharacter();
      tToken.mLiteral += tCharacter;
      continue;
    }

    if (tCharacter[0] == 0x0A || tCharacter[0] == EOF) {
      // TODO: report unterminated string literal
    }
    ReadCharacter();
    break;
  }
  mTokens.push_back(tToken);
}

void Lexer::ReadPunctuation(const std::string& aCharacter) {
  Token tToken;
  tToken.mFileName = mFileName;
  tToken.mLine = mLine;
  tToken.mCursor = mCursor;
  tToken.mLiteral = aCharacter;
  ReadCharacter();

  if (aCharacter == ".") {
    tToken.mType = TokenType::DOT;
  } else if (aCharacter == ",") {
    tToken.mType = TokenType::COMMA;
  } else if (aCharacter == ":") {
    tToken.mType = TokenType::COLON;
  } else if (aCharacter == ";") {
    tToken.mType = TokenType::SEMICOLON;
  } else if (aCharacter == ">") {
    tToken.mType = TokenType::GREATER;
  } else if (aCharacter == "<") {
    tToken.mType = TokenType::LESSER;
  } else if (aCharacter == "+") {
    tToken.mType = TokenType::PLUS;
  } else if (aCharacter == "-") {
    tToken.mType = TokenType::MINUS;
  } else if (aCharacter == "*") {
    tToken.mType = TokenType::STAR;
  } else if (aCharacter == "/") {
    tToken.mType = TokenType::SLASH;
  } else if (aCharacter == "%") {
    tToken.mType = TokenType::PERCENT;
  } else if (aCharacter == "=") {
    tToken.mType = TokenType::EQUAL;
  } else if (aCharacter == "(") {
    tToken.mType = TokenType::LEFT_PAREN;
  } else if (aCharacter == ")") {
    tToken.mType = TokenType::RIGHT_PAREN;
  } else if (aCharacter == "{") {
    tToken.mType = TokenType::LEFT_BRACE;
  } else if (aCharacter == "}") {
    tToken.mType = TokenType::RIGHT_BRACE;
  } else if (aCharacter == "[") {
    tToken.mType = TokenType::LEFT_BRACKET;
  } else if (aCharacter == "]") {
    tToken.mType = TokenType::RIGHT_BRACKET;
  } else if (aCharacter == "!") {
    tToken.mType = TokenType::BANG;
  } else {
    // TODO: report unrecognized token error
  }

  std::string tPeekCharacter = PeekCharacter();
  if (aCharacter == "!" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = "!=";
    tToken.mType = TokenType::BANG_EQUAL;
  } else if (aCharacter == "=" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = "==";
    tToken.mType = TokenType::EQUAL_EQUAL;
  } else if (aCharacter == ":" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = ":=";
    tToken.mType = TokenType::COLON_EQUAL;
  } else if (aCharacter == ">" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = ">=";
    tToken.mType = TokenType::GREATER_EQUAL;
  } else if (aCharacter == "<" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = "<=";
    tToken.mType = TokenType::LESSER_EQUAL;
  } else if (aCharacter == "+" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = "+=";
    tToken.mType = TokenType::PLUS_EQUAL;
  } else if (aCharacter == "-" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = "-=";
    tToken.mType = TokenType::MINUS_EQUAL;
  } else if (aCharacter == "*" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = "*=";
    tToken.mType = TokenType::STAR_EQUAL;
  } else if (aCharacter == "/" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = "/=";
    tToken.mType = TokenType::SLASH_EQUAL;
  } else if (aCharacter == "%" && tPeekCharacter == "=") {
    ReadCharacter();
    tToken.mLiteral = "%=";
    tToken.mType = TokenType::PERCENT_EQUAL;
  } else if (aCharacter == "_" && IsIdentifier(tPeekCharacter)) {
    std::string tCharacter = "";
    tToken.mLiteral = "_";
    tToken.mType = TokenType::IDENTIFIER;
    while(true) {
      tCharacter = PeekCharacter();
      if (IsIdentifier(tCharacter)) {
        tToken.mLiteral += tCharacter;
        tCharacter = ReadCharacter();
        continue;
      }
      break;
    }
  }

  mTokens.push_back(tToken);
}

bool Lexer::IsIdentifier(const std::string& aCharacter) {
  if (aCharacter.size() == 0) {
    return false;
  }
  for (auto& tCharacter : aCharacter) {
    if ((tCharacter >= 'A' && tCharacter <= 'Z') ||
        (tCharacter >= 'a' && tCharacter <= 'z') ||
        (tCharacter >= '0' && tCharacter <= '9') ||
        (tCharacter == '_') ||
        ((unsigned char)tCharacter >= 0x80)) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}

void Lexer::ReadIdentifier() {
  Token tToken;
  tToken.mFileName = mFileName;
  tToken.mLine = mLine;
  tToken.mCursor = mCursor;
  tToken.mType = TokenType::IDENTIFIER;
  tToken.mLiteral = "";

  std::string tCharacter = "";
  while(true) {
    tCharacter = PeekCharacter();
    if (IsIdentifier(tCharacter)) {
      tToken.mLiteral += tCharacter;
      tCharacter = ReadCharacter();
      continue;
    }
    break;
  }

  if (tToken.mLiteral == "null") {
    tToken.mType = TokenType::NULL_;
  } else if (tToken.mLiteral == "true") {
    tToken.mType = TokenType::TRUE;
  } else if (tToken.mLiteral == "false") {
    tToken.mType = TokenType::FALSE;
  } else if (tToken.mLiteral == "if") {
    tToken.mType = TokenType::IF;
  } else if (tToken.mLiteral == "else") {
    tToken.mType = TokenType::ELSE;
  } else if (tToken.mLiteral == "while") {
    tToken.mType = TokenType::WHILE;
  } else if (tToken.mLiteral == "for") {
    tToken.mType = TokenType::FOR;
  } else if (tToken.mLiteral == "in") {
    tToken.mType = TokenType::IN;
  } else if (tToken.mLiteral == "and") {
    tToken.mType = TokenType::AND;
  } else if (tToken.mLiteral == "or") {
    tToken.mType = TokenType::OR;
  } else if (tToken.mLiteral == "not") {
    tToken.mType = TokenType::NOT;
  } else if (tToken.mLiteral == "break") {
    tToken.mType = TokenType::BREAK;
  } else if (tToken.mLiteral == "continue") {
    tToken.mType = TokenType::CONTINUE;
  } else if (tToken.mLiteral == "function") {
    tToken.mType = TokenType::FUNCTION;
  } else if (tToken.mLiteral == "return") {
    tToken.mType = TokenType::RETURN;
  } else if (tToken.mLiteral == "import") {
    tToken.mType = TokenType::IMPORT;
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
      } else if (tCharacter[0] == '"') { // string
        ReadString();
      } else if (ispunct(tCharacter[0])) { // punctuation
        ReadPunctuation(tCharacter);
      } else if (IsIdentifier(tCharacter)) { // identifier
        ReadIdentifier();
      } else if (tCharacter[0] == ' ' || // whitespace
                 tCharacter[0] == 0x08 ||
                 tCharacter[0] == 0x09 || 
                 tCharacter[0] == 0x0D) {
        ReadWhitespace();
      }

      if (tCharacter[0] == '\n') { // newline
        mLine += 1;
        ReadCharacter();
        mCursor = 1;
      }
      continue;
    }
  }

  Token tToken;
  tToken.mFileName = mFileName;
  tToken.mLine = mLine;
  tToken.mCursor = mCursor;
  tToken.mType = TokenType::EOF_;
  tToken.mLiteral = "";
  mTokens.push_back(tToken);
}