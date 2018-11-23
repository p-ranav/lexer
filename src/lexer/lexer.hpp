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

  explicit Lexer(const std::string& aFileName, const std::string& aSource);

};