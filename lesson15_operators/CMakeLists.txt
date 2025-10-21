cmake_minimum_required(VERSION 3.10)
project(Lesson15_Operators)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(operators_demo operators.cpp)
add_executable(exercises exercises.cpp)

install(TARGETS operators_demo exercises DESTINATION bin)
