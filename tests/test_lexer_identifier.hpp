#pragma once
#include <catch.hpp>
#include <lexer.hpp>
#include <clocale>

TEST_CASE("Identifier 'foo'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "foo";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::IDENTIFIER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "foo");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 4);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Identifier 'foo_'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "foo_";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::IDENTIFIER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "foo_");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 5);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Identifier '_foo'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "_foo";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::IDENTIFIER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "_foo");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 5);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Identifier 'foo_bar'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "foo_bar";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::IDENTIFIER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "foo_bar");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 8);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Identifier 'foo_123'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "foo_123";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::IDENTIFIER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "foo_123");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 8);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}

TEST_CASE("Identifier 'f123'", "[lexer]") {
  std::string tFileName = "";
  std::string tSource = "f123";
  Lexer tLexer(tFileName, tSource);
  tLexer.Tokenize();
  REQUIRE(tLexer.mTokens.size() == 2);
  REQUIRE(tLexer.mTokens[0].mFileName == "");
  REQUIRE(tLexer.mTokens[0].mLine == 1);
  REQUIRE(tLexer.mTokens[0].mCursor == 1);
  REQUIRE(tLexer.mTokens[0].mType == TokenType::IDENTIFIER);
  REQUIRE(tLexer.mTokens[0].mLiteral == "f123");
  REQUIRE(tLexer.mTokens[1].mFileName == "");
  REQUIRE(tLexer.mTokens[1].mLine == 1);
  REQUIRE(tLexer.mTokens[1].mCursor == 5);
  REQUIRE(tLexer.mTokens[1].mType == TokenType::EOF_);
  REQUIRE(tLexer.mTokens[1].mLiteral == "");  
}