cmake_minimum_required(VERSION 3.8)
project(lab1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/IniParser.cpp src/IniParser.h)
add_executable(lab1 ${SOURCE_FILES})
