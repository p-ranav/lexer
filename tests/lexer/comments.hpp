#pragma once
#include <catch.hpp>
#include <lexer.hpp>
#include <clocale>

TEST_CASE("Line comments", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "// line comment";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 1);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 2);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[0].mLiteral == "");
}

TEST_CASE("Block comments", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "/* block comment */";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 1);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 20);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[0].mLiteral == "");
}

TEST_CASE("Block comments & line comments", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "/* block comment */ // line comment";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 1);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 2);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[0].mLiteral == "");
}