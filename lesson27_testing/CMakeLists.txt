cmake_minimum_required(VERSION 3.10)
project(Lesson27_Testing)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(test_demo test_demo.cpp)

add_test(NAME UnitTests COMMAND test_demo)
