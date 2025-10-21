cmake_minimum_required(VERSION 3.10)
project(Lesson12_Constructors)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# デモプログラム
add_executable(constructors_demo constructors.cpp)

# 演習プログラム
add_executable(exercises exercises.cpp)

# インストール設定（オプション）
install(TARGETS constructors_demo exercises DESTINATION bin)
