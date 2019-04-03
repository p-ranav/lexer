#pragma once
#include <utf8.hpp>
#include <token.hpp>
#include <iostream>
#include <vector>
#include <cassert>

namespace lexer {

  struct Lexer {
    std::string mSource;          // original source as string buffer
    int mIndex;                   // current position in source
    std::string mFileName;        // name of source file
    int mLine;                    // line number in source file
    int mCursor;                  // cursor position in mLine
    std::vector<Token> mTokens;   // output of lexer - a list of tokens

    // Constructs a Lexer object
    explicit Lexer(const std::string& aFileName, const std::string& aSource);

    // ReadCharacter returns next character from mSource
    // ReadCharacter supports multi-byte UTF-8 character
    // - this is why the return type is std::string and not char
    // if mSource = 世界, ReadCharacter() will return "世" 
    // ReadCharacter advances mIndex
    std::string ReadCharacter(bool aUpdateIndex = true);

    // PeekCharacter returns next character from mSource
    // PeekCharacter supports multi-byte UTF-8 character
    // - this is why the return type is std::string and not char
    // if mSource = 世界, PeekCharacter() will return "世" 
    // PeekCharacter does not advances mIndex
    std::string PeekCharacter();

    // ReadComment consumes block and line comments
    // Consumes /* */ as block comment
    // Consumes // as line comment
    // Consumes and classifies '/' as SLASH token
    void ReadComment();

    // ReadNumber consumes a number
    // Numbers can be integer or floating point numbers
    // Integer numbers are classified as INTEGER tokens
    // Floating point numbers are classified as DOUBLE tokens
    void ReadNumber(const std::string& aCharacter);

    // ReadSingleQuotedString consumes a single-quoted string literal
    // Parses single-quoted string-literal, e.g., 'Hello'
    // ReadSingleQuotedString supports multi-byte UTF-8 characters
    void ReadSingleQuotedString();

    // ReadDoubleQuotedString consumes a quoted string literal
    // Parses double-quoted string-literal, e.g., "Hello"
    // ReadDoubleQuotedString supports multi-byte UTF-8 characters
    void ReadDoubleQuotedString();

    // ReadPunctuation consumes a punctuation token
    // If the character can be classified as a TokenType,
    // ReadPunctuation will classify this token
    // If not, ReadPunctuation will report an error 
    void ReadPunctuation(const std::string& aCharacter);

    // IsIdentifier returns true if aCharacter is a valid 
    // identifier, e.g., x, y, abc_def, abc123, etc.
    // IsIdentifier supports UTF-8 characters and treats
    // all characters >= 0x80 as valid identifiers
    bool IsIdentifier(const std::string& aCharacter);

    // ReadIdentifier consumes a valid identifier
    // ReadIdentifier supports UTF-8 characters
    // ReadIdentifier classifies keywords in TokenType
    void ReadIdentifier();

    // ReadWhitespace consumes white space characters
    // Whitespace includes ' ', 0x09, 0x08 and 0x0D
    void ReadWhitespace();

    // Tokenize transforms the input source (mSource)
    // into a list of lexical tokens (mTokens)
    void Tokenize();

  };

}