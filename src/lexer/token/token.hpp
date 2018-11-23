#pragma once
#include <string>

using std::string;

struct Token {
  string mType;
  string mLiteral;
  string mFileName;
  int mLine;
  int mCursor;
};