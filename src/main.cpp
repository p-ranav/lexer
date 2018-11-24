#include <lexer.hpp>

int main() {
  Lexer lexer("", "// line comment \n/ 5 3.14 \n10");
  lexer.Tokenize();

  lexer.mLine = 1; lexer.mCursor = 1;
  lexer.mSource = "\"Hello World\" \"Hello, 世界\" ";
  lexer.Tokenize();
  return 0;
}