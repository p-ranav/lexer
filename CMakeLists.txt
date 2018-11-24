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
  )
ADD_LIBRARY(LEXER STATIC ${LEXER_SOURCES})
INCLUDE_DIRECTORIES("src/lexer")
set_target_properties(LEXER PROPERTIES OUTPUT_NAME lexer)
TARGET_LINK_LIBRARIES(LEXER)

# Main executable
file(GLOB EXECUTABLE_SOURCES 
    "src/main.cpp" 
)
ADD_EXECUTABLE(COMPILER ${EXECUTABLE_SOURCES})
set_target_properties(COMPILER PROPERTIES OUTPUT_NAME main)

#Link any of the created libraries
TARGET_LINK_LIBRARIES(COMPILER LEXER)

# Set ${PROJECT_NAME} as the startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT COMPILER)
set_property(TARGET COMPILER PROPERTY CXX_STANDARD 17)

# Tests
file(GLOB TESTS_SOURCES 
    "tests/*.cpp" 
    "tests/lexer/*.hpp"
)
INCLUDE_DIRECTORIES("tests" "tests/lexer")
ADD_EXECUTABLE(TESTS ${TESTS_SOURCES})
set_target_properties(TESTS PROPERTIES OUTPUT_NAME tests) # tests.exe
TARGET_LINK_LIBRARIES(TESTS LEXER)

# make check - runs unit tests
if (UNIX)
add_custom_target(check COMMAND ./tests)
endif(UNIX)