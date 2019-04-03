#pragma once
#include <string>
#include <map>

namespace lexer {

  enum TokenType {
    // Special tokens
    ILLEGAL, EOF_,

    // Literals
    IDENTIFIER, CHARACTER, STRING, INTEGER, DOUBLE,

    // Operators
    PLUS, MINUS, STAR, SLASH, PERCENT, BANG,
    EQUAL, BANG_EQUAL, EQUAL_EQUAL, COLON_EQUAL,
    GREATER, GREATER_EQUAL, LESSER, LESSER_EQUAL,
    PLUS_EQUAL, MINUS_EQUAL, STAR_EQUAL,
    SLASH_EQUAL, PERCENT_EQUAL,

    // Delimiters
    DOT, COMMA, COLON, SEMICOLON,

    // Brackets
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    LEFT_BRACKET, RIGHT_BRACKET,

    // KEYWORDS
    NULL_, TRUE_, FALSE_, IF, ELSE, WHILE, FOR, IN_, AND, OR, NOT,
    BREAK, CONTINUE, FUNCTION, RETURN, IMPORT
  };

  struct Token {
    TokenType mType;         // type of lexer token, e.g., INTEGER
    std::string mLiteral;    // value of lexer token, e.g., "5"
    std::string mFileName;   // source file of token
    int mLine;               // line number in source file
    int mCursor;             // cursor number in line of source file
  };

}