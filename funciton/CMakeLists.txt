cmake_minimum_required(VERSION 3.25.1)

project(cxx_function VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

file(GLOB SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
message(STATUS "SOURCE_DIR = ${SOURCE_DIR}")
add_executable(function ${SOURCE_DIR})