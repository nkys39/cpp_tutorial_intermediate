# Lesson 14: 名前空間と列挙型

## 学習目標
- 名前空間（namespace）の概念と使い方を理解する
- 名前の衝突を回避する方法を学ぶ
- 列挙型（enum）の使い方を学ぶ
- enum class の利点を理解する

## 名前空間とは？

名前空間は、識別子（変数、関数、クラスなど）のスコープを定義し、名前の衝突を防ぐための仕組みです。

### 基本的な構文

```cpp
namespace Math {
    const double PI = 3.14159;

    double add(double a, double b) {
        return a + b;
    }

    class Calculator {
        // ...
    };
}

// 使用方法
double result = Math::add(5, 3);
cout << Math::PI << endl;
```

## using 宣言

### using ディレクティブ

```cpp
using namespace Math;

// これで Math:: を省略できる
double result = add(5, 3);
cout << PI << endl;
```

**注意**: ヘッダーファイルでは `using namespace` を使用しないでください！

### using 宣言（特定の識別子のみ）

```cpp
using Math::PI;

cout << PI << endl;          // OK
double result = Math::add(5, 3);  // add は using していないので Math:: が必要
```

## ネストした名前空間

```cpp
namespace Company {
    namespace HR {
        class Employee {
            // ...
        };
    }

    namespace IT {
        class Employee {
            // ...  （HR::Employee と異なるクラス）
        };
    }
}

Company::HR::Employee emp1;
Company::IT::Employee emp2;

// C++17以降の簡潔な書き方
namespace Company::HR {
    class Manager {
        // ...
    };
}
```

## 匿名名前空間

ファイル内でのみ使用する内部リンケージを作成します。

```cpp
namespace {
    // このファイル内でのみアクセス可能
    int internalCounter = 0;

    void internalFunction() {
        // ...
    }
}
```

## 列挙型（enum）

### 従来の enum

```cpp
enum Color {
    RED,
    GREEN,
    BLUE
};

Color c = RED;

if (c == RED) {
    cout << "赤色です" << endl;
}
```

**問題点**:
- スコープが広い（列挙子が外部にリーク）
- 暗黙の型変換が発生

```cpp
enum Color { RED, GREEN, BLUE };
enum Status { RED, YELLOW, GREEN };  // エラー：RED と GREEN が重複

int x = RED;  // OK だが危険
```

## enum class（C++11）

スコープ付き列挙型で、上記の問題を解決します。

```cpp
enum class Color {
    Red,
    Green,
    Blue
};

enum class Status {
    Red,     // OK：Color::Red と衝突しない
    Yellow,
    Green
};

Color c = Color::Red;
Status s = Status::Red;

// int x = Color::Red;  // エラー：暗黙の型変換なし
int x = static_cast<int>(Color::Red);  // 明示的な変換が必要
```

### enum class の利点

1. **スコープの明確化**: 列挙子がクラスのスコープ内にある
2. **型安全**: 暗黙の型変換を防ぐ
3. **名前の衝突を回避**: 異なる列挙型で同じ名前を使用可能

## 基底型の指定

```cpp
enum class Status : uint8_t {
    OK = 0,
    Warning = 1,
    Error = 2
};

// サイズは 1 バイト
```

## switch 文での使用

```cpp
enum class TrafficLight {
    Red,
    Yellow,
    Green
};

TrafficLight light = TrafficLight::Red;

switch (light) {
    case TrafficLight::Red:
        cout << "停止" << endl;
        break;
    case TrafficLight::Yellow:
        cout << "注意" << endl;
        break;
    case TrafficLight::Green:
        cout << "進行" << endl;
        break;
}
```

## 実践例

`namespaces.cpp` には以下の例が含まれています：
1. 名前空間の基本的な使い方
2. ネストした名前空間
3. 名前の衝突の回避
4. enum と enum class の比較
5. 実用的な列挙型の使用例

## 演習問題

`exercises.cpp` で以下を実装してください：

### 演習1: ゲームの名前空間
`Game` 名前空間を作成し、キャラクター管理システムを実装してください。

### 演習2: 列挙型を使った状態管理
`enum class` を使ってゲームの状態を管理してください。

### 演習3: 数学ライブラリ
`Math` 名前空間に関数と定数を実装してください。

## ビルド方法

```bash
cd lesson14_namespaces
mkdir build
cd build
cmake ..
make
./namespaces_demo
./exercises
```

## 次のステップ

Lesson 15では、演算子オーバーロードを学び、カスタムクラスで演算子を定義する方法を理解します。
