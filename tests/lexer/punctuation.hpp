#pragma once
#include <catch.hpp>
#include <lexer.hpp>
#include <clocale>

TEST_CASE("Dot '.'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = ".";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::DOT);
  REQUIRE(tLexer.mTokens[0].mLiteral == ".");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Comma ','", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = ",";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::COMMA);
  REQUIRE(tLexer.mTokens[0].mLiteral == ",");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Colon ':'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = ":";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::COLON);
  REQUIRE(tLexer.mTokens[0].mLiteral == ":");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Semicolon ':'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = ";";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::SEMICOLON);
  REQUIRE(tLexer.mTokens[0].mLiteral == ";");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Equal '='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Bang '!'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "!";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::BANG);
  REQUIRE(tLexer.mTokens[0].mLiteral == "!");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Equal equal '=='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "==";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::EQUAL_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "==");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Bang equal '!='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "!=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::BANG_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "!=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Greater '>'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = ">";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::GREATER);
  REQUIRE(tLexer.mTokens[0].mLiteral == ">");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Greater or equal '>='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = ">=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::GREATER_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == ">=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Lesser '<'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "<";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::LESSER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "<");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Lesser or equal '>='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "<=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::LESSER_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "<=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Plus '+'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "+";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::PLUS);
  REQUIRE(tLexer.mTokens[0].mLiteral == "+");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Minus '-'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "-";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::MINUS);
  REQUIRE(tLexer.mTokens[0].mLiteral == "-");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Star '*'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "*";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::STAR);
  REQUIRE(tLexer.mTokens[0].mLiteral == "*");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Slash '/'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "/";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::SLASH);
  REQUIRE(tLexer.mTokens[0].mLiteral == "/");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Percent '%'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "%";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::PERCENT);
  REQUIRE(tLexer.mTokens[0].mLiteral == "%");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Plus equal '+='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "+=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::PLUS_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "+=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Minus equal '-='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "-=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::MINUS_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "-=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Star equal '*='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "*=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::STAR_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "*=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Slash equal '/='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "/=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::SLASH_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "/=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Percent equal '%='", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "%=";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::PERCENT_EQUAL);
  REQUIRE(tLexer.mTokens[0].mLiteral == "%=");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Left Paren '('", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "(";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::LEFT_PAREN);
  REQUIRE(tLexer.mTokens[0].mLiteral == "(");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Left Brace '{'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "{";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::LEFT_BRACE);
  REQUIRE(tLexer.mTokens[0].mLiteral == "{");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Left Bracket '['", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "[";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::LEFT_BRACKET);
  REQUIRE(tLexer.mTokens[0].mLiteral == "[");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Right Paren ')'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = ")";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::RIGHT_PAREN);
  REQUIRE(tLexer.mTokens[0].mLiteral == ")");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Right Brace '}'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "}";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::RIGHT_BRACE);
  REQUIRE(tLexer.mTokens[0].mLiteral == "}");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Right Bracket ']'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "]";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::RIGHT_BRACKET);
  REQUIRE(tLexer.mTokens[0].mLiteral == "]");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}