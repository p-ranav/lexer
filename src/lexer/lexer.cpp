#include <lexer.hpp>

Lexer::Lexer(const std::string& aFileName, const std::string& aSource) :
  mSource(aSource),
  mIndex(0),
  mFileName(aFileName),
  mLine(1),
  mCursor(1) {}

std::string Lexer::NextCharacter(bool aUpdateIndex) {
  std::string tResult = "";
  int tLength = 1; // TODO: Change to GetUTF8SequenceLength(..)
  for (int i = 0; i < tLength; i++, mIndex++)
    tResult += mSource[mIndex];

  if (!aUpdateIndex)
    mIndex -= tLength;
  else
    mCursor += 1;
  
  return tResult;
}

std::string Lexer::PeekCharacter() {
  return NextCharacter(false);
}