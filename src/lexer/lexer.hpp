#pragma once
#include <utf8.hpp>
#include <token.hpp>
#include <iostream>
#include <vector>
#include <cassert>

struct Lexer {
  std::string mSource;          // original source as string buffer
  int mIndex;                   // current position in source
  std::string mFileName;        // name of source file
  int mLine;                    // line number in source file
  int mCursor;                  // cursor position in mLine
  std::vector<Token> mTokens;   // output of lexer - a list of tokens

  // Constructs a Lexer object
  explicit Lexer(const std::string& aFileName, const std::string& aSource);

  // ReadCharacter returns next character from mSource
  // ReadCharacter supports multi-byte UTF-8 character
  // - this is why the return type is std::string
  // if mSource = 世界, ReadCharacter() will return "世" 
  // ReadCharacter advances mIndex
  std::string ReadCharacter(bool aUpdateIndex = true);

  // PeekCharacter returns next character from mSource
  // PeekCharacter supports multi-byte UTF-8 character
  // - this is why the return type is std::string
  // if mSource = 世界, PeekCharacter() will return "世" 
  // PeekCharacter does not advances mIndex
  std::string PeekCharacter();

  // ReadComment consumes block and line comments
  // Consumes /* */ as block comment
  // Consumes // as line comment
  // Consumes and classifies '/' as SLASH token
  void ReadComment();

  // ReadWhitespace consumes white space characters
  // Whitespace includes ' ', 0x09, 0x08 and 0x0D
  void ReadWhitespace();

  // Tokenize transforms the input source (mSource)
  // into a list of lexical tokens (mTokens)
  void Tokenize();

};