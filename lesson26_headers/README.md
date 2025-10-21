# Lesson 26: ヘッダとソースの分離

## 学習目標
- .h と .cpp の使い分けを理解する
- インクルードガードの重要性を学ぶ
- プロジェクト構成のベストプラクティスを理解する

## ヘッダファイル (.h)

```cpp
// calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:
    int add(int a, int b);
    int subtract(int a, int b);
};

#endif
```

## ソースファイル (.cpp)

```cpp
// calculator.cpp
#include "calculator.h"

int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::subtract(int a, int b) {
    return a - b;
}
```

## プロジェクト構成

```
project/
├── include/
│   └── mylib.h
├── src/
│   ├── mylib.cpp
│   └── main.cpp
└── CMakeLists.txt
```
