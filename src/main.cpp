#include <lexer.hpp>

int main() {
  Lexer lexer("", "// line comment \n/ 5 3.14 \n10");
  lexer.Tokenize();
  return 0;
}