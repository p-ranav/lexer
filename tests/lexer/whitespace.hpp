#pragma once
#include <catch.hpp>
#include <lexer.hpp>
#include <clocale>

TEST_CASE("Whitespace ' '", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = " ";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 1);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 2);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[0].mLiteral == "");
}

TEST_CASE("Whitespace '    '", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "    ";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 1);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 5);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[0].mLiteral == "");
}