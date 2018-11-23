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