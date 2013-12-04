cmake_minimum_required(VERSION 2.8)
project(matrix)

add_library(matrix STATIC matrix.cpp)
add_executable(test test.cpp)

target_link_libraries(test matrix)
