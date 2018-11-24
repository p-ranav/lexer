#include <lexer.hpp>

int main() {
  Lexer lexer("", "// line comment \n/");
  lexer.Tokenize();
  return 0;
}