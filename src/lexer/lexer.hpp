#pragma once
#include <token.hpp>
#include <vector>

struct Lexer {
  std::string mSource;                  // original source as string buffer
  int mIndex;                           // current position in source
  std::string mFileName;                // name of source file
  int mLine;                            // line number in source file
  int mCursor;                          // cursor position in mLine
  std::vector<std::string> mTokens;     // output of lexer - a list of tokens

  // Constructs a Lexer object
  explicit Lexer(const std::string& aFileName, const std::string& aSource);

  // NextCharacter returns next character from mSource
  // NextCharacter supports multi-byte UTF-8 character
  // if mSource = 世界, NextCharacter() will return "世" 
  // NextCharacter advances mIndex
  std::string NextCharacter(bool aUpdateIndex = true);

  // PeekCharacter returns next character from mSource
  // PeekCharacter supports multi-byte UTF-8 character
  // if mSource = 世界, PeekCharacter() will return "世" 
  // PeekCharacter does not advances mIndex
  std::string PeekCharacter();
};