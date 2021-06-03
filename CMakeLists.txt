cmake_minimum_required(VERSION 3.17)
project(clang_1205_test)

set(CMAKE_CXX_STANDARD 17)

add_executable(clang_1205_test main.cpp atomic_issue.cpp)