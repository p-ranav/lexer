#pragma once
#include <catch.hpp>
#include <lexer.hpp>
#include <clocale>
using namespace lexer;

TEST_CASE("Integer '0'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "0";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::INTEGER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "0");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Integer '5'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "5";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::INTEGER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "5");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Integer '42'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "42";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::INTEGER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "42");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 3);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Integer '-96'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "-96";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 3);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::MINUS);
  REQUIRE(tLexer.mTokens[0].mLiteral == "-");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 2);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::INTEGER);
  REQUIRE(tLexer.mTokens[1].mLiteral == "96");
  REQUIRE(tLexer.mTokens[2].mFileName == "");
  REQUIRE(tLexer.mTokens[2].mLine == 1);
  REQUIRE(tLexer.mTokens[2].mCursor == 4);
  REQUIRE(tLexer.mTokens[2].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[2].mLiteral == "");  
}