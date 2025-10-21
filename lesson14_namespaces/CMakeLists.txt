cmake_minimum_required(VERSION 3.10)
project(Lesson14_Namespaces)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(namespaces_demo namespaces.cpp)
add_executable(exercises exercises.cpp)

install(TARGETS namespaces_demo exercises DESTINATION bin)
