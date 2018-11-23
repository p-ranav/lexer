#pragma once
#include <string>

enum TokenType {
  // Special tokens
  ILLEGAL, EOF,

  // Literals
  IDENTIFIER, CHARACTER, STRING, INTEGER, DOUBLE,

  // Operators
  PLUS, MINUS, STAR, SLASH, PERCENT, BANG,
  EQUAL, BANG_EQUAL, EQUAL_EQUAL, 
  GREATER, GREATER_EQUAL, LESSER, LESSER_EQUAL

  // Delimiters
  DOT, COMMA, COLON, SEMICOLON,

  // Brackets
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, 
  LEFT_BRACKET, RIGHT_BRACKET,

  // KEYWORDS
  NULL_, VAR, TRUE, FALSE, IF, ELSE, WHILE, FOR, IN, NOT, 
  FUNCTION, RETURN, IMPORT
};

struct Token {
  std::string mType;
  std::string mLiteral;
  std::string mFileName;
  int mLine;
  int mCursor;
};