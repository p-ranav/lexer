#pragma once
#include <catch.hpp>
#include <lexer.hpp>
#include <clocale>

TEST_CASE("String 'Hello World'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "\"Hello World\"";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::STRING);
  REQUIRE(tLexer.mTokens[0].mLiteral == "Hello World");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 14);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("String 'Hello 世界'", "[lexer]") {
  setlocale(LC_ALL, "");
  std::string tFileName = "";
  std::string tSource = "\"Hello 世界\"";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::STRING);
  REQUIRE(tLexer.mTokens[0].mLiteral == "Hello 世界");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 11);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("String 'ο Δίας'", "[lexer]") {
  setlocale(LC_ALL, "");
  std::string tFileName = "";
  std::string tSource = "\"ο Δίας\"";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::STRING);
  REQUIRE(tLexer.mTokens[0].mLiteral == "ο Δίας");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 9);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}