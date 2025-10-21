cmake_minimum_required(VERSION 3.10)
project(CPP_Tutorial_Intermediate)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# サブディレクトリを追加

# オブジェクト指向編（Lesson 11-15）
add_subdirectory(lesson11_classes)
add_subdirectory(lesson12_constructors)
add_subdirectory(lesson13_inheritance)
add_subdirectory(lesson14_namespaces)
add_subdirectory(lesson15_operators)

# STLコンテナ編（Lesson 16-21）
add_subdirectory(lesson16_vector_deque)
add_subdirectory(lesson17_list)
add_subdirectory(lesson18_stack_queue)
add_subdirectory(lesson19_set)
add_subdirectory(lesson20_map)
add_subdirectory(lesson21_unordered)

# STL応用と実践編（Lesson 22-28）
add_subdirectory(lesson22_algorithms)
add_subdirectory(lesson23_iterators_lambda)
add_subdirectory(lesson24_exceptions)
add_subdirectory(lesson25_file_io)
add_subdirectory(lesson26_headers)
add_subdirectory(lesson27_testing)
add_subdirectory(lesson28_libraries)
