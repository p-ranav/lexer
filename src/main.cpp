#include <lexer.hpp>

int main() {
  Lexer lexer("", "// line comment \n/ 5 3.14 \n10");
  lexer.Tokenize();

  lexer.mLine = 1; lexer.mCursor = 1;
  lexer.mTokens.clear();
  lexer.mSource = "\"Hello World\" \"Hello, 世界\" ";
  lexer.Tokenize();

  lexer.mLine = 1; lexer.mCursor = 1;
  lexer.mTokens.clear();
  lexer.mSource = "!= == >= <= += -= *= /= %= :=";
  lexer.Tokenize();

  lexer.mLine = 1; lexer.mCursor = 1;
  lexer.mTokens.clear();
  lexer.mSource = "a, b, c, d";
  lexer.Tokenize();

  lexer.mLine = 1; lexer.mCursor = 1;
  lexer.mTokens.clear();
  lexer.mSource = "test, test_value, testValue, test_value_";
  lexer.Tokenize();

  lexer.mLine = 1; lexer.mCursor = 1;
  lexer.mTokens.clear();
  lexer.mSource = "_test123, _test_123_value_世界";
  lexer.Tokenize();

  lexer.mLine = 1; lexer.mCursor = 1;
  lexer.mTokens.clear();
  lexer.mSource = "true false if else while for in and or not";
  lexer.Tokenize();

  lexer.mLine = 1; lexer.mCursor = 1;
  lexer.mTokens.clear();
  lexer.mSource = "break continue function return import";
  lexer.Tokenize();
  return 0;
}