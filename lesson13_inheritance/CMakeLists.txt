cmake_minimum_required(VERSION 3.10)
project(Lesson13_Inheritance)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# デモプログラム
add_executable(inheritance_demo inheritance.cpp)

# 演習プログラム
add_executable(exercises exercises.cpp)

# インストール設定（オプション）
install(TARGETS inheritance_demo exercises DESTINATION bin)
