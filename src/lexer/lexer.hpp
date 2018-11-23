#pragma once
#include <utf8.hpp>
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
};