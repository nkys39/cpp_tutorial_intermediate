cmake_minimum_required(VERSION 3.10)
project(Lesson11_Classes)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# デモプログラム
add_executable(classes_demo classes.cpp)

# 演習プログラム
add_executable(exercises exercises.cpp)

# インストール設定（オプション）
install(TARGETS classes_demo exercises DESTINATION bin)
