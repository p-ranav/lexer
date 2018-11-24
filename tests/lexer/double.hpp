#pragma once
#include <catch.hpp>
#include <lexer.hpp>
#include <clocale>

TEST_CASE("Double '0.0'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "0.0";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::DOUBLE);
  REQUIRE(tLexer.mTokens[0].mLiteral == "0.0");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 4);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Double '3.14'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "3.14";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::DOUBLE);
  REQUIRE(tLexer.mTokens[0].mLiteral == "3.14");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 5);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Double '2.71828'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "2.71828";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::DOUBLE);
  REQUIRE(tLexer.mTokens[0].mLiteral == "2.71828");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 8);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Double '1.61803398875'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "1.61803398875";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::DOUBLE);
  REQUIRE(tLexer.mTokens[0].mLiteral == "1.61803398875");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 14);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}