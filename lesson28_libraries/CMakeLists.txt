cmake_minimum_required(VERSION 3.10)
project(Lesson28_Libraries)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 静的ライブラリ
add_library(mylib_static STATIC mylib.cpp)

# 動的ライブラリ
add_library(mylib_shared SHARED mylib.cpp)

# 静的ライブラリを使用するアプリ
add_executable(app_static main.cpp)
target_link_libraries(app_static mylib_static)

# 動的ライブラリを使用するアプリ
add_executable(app_shared main.cpp)
target_link_libraries(app_shared mylib_shared)
