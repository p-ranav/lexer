cmake_minimum_required(VERSION 3.6)
project(COMPILER)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Disable deprecation for windows
if (WIN32)
	add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
endif()

# LEXER library
file(GLOB LEXER_SOURCES 
  "src/lexer/*.cpp" 
  "src/lexer/*.hpp"
  "src/lexer/token/*.hpp"
  "src/lexer/token/*.cpp"
  )
ADD_LIBRARY(LEXER STATIC ${LEXER_SOURCES})
INCLUDE_DIRECTORIES("src/lexer" "src/lexer/token")
set_target_properties(LEXER PROPERTIES OUTPUT_NAME lexer)
TARGET_LINK_LIBRARIES(LEXER)