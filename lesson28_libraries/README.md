# Lesson 28: ライブラリの作成

## 学習目標
- 静的ライブラリ (.a) の作成方法を学ぶ
- 動的ライブラリ (.so/.dll) の作成方法を学ぶ
- CMake でのライブラリビルドを理解する

## 静的ライブラリ

CMakeLists.txt:
```cmake
add_library(mylib STATIC mylib.cpp)
add_executable(app main.cpp)
target_link_libraries(app mylib)
```

## 動的ライブラリ

CMakeLists.txt:
```cmake
add_library(mylib SHARED mylib.cpp)
add_executable(app main.cpp)
target_link_libraries(app mylib)
```

## 静的 vs 動的

- **静的**: 実行ファイルに組み込まれる、配布が簡単
- **動的**: 複数のプログラムで共有、メモリ節約
