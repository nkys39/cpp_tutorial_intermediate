# Lesson 15: 演算子オーバーロード

## 学習目標
- 演算子オーバーロードの概念を理解する
- 算術演算子のオーバーロードを学ぶ
- 比較演算子のオーバーロードを学ぶ
- ストリーム演算子（<<, >>）のオーバーロードを学ぶ
- 代入演算子とコピー代入演算子を理解する

## 演算子オーバーロードとは？

演算子オーバーロードは、カスタムクラスで演算子（+, -, *, / など）の動作を定義する機能です。

### 基本的な構文

```cpp
class Vector2D {
public:
    double x, y;

    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // + 演算子のオーバーロード
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
};

Vector2D v1(1, 2);
Vector2D v2(3, 4);
Vector2D v3 = v1 + v2;  // (4, 6)
```

## 算術演算子

```cpp
class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 加算
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 減算
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // 乗算
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }
};
```

## 比較演算子

```cpp
class Date {
private:
    int year, month, day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    bool operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Date& other) const {
        return other < *this;
    }
};
```

## ストリーム演算子

```cpp
class Point {
private:
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // << 演算子（friend 関数として定義）
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    // >> 演算子
    friend istream& operator>>(istream& is, Point& p) {
        is >> p.x >> p.y;
        return is;
    }
};

Point p(3, 4);
cout << p << endl;  // (3, 4)
```

## 代入演算子

```cpp
class DynamicArray {
private:
    int* data;
    int size;

public:
    // コピー代入演算子
    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {  // 自己代入チェック
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
};
```

## 添字演算子

```cpp
class Array {
private:
    int data[10];

public:
    int& operator[](int index) {
        return data[index];
    }

    const int& operator[](int index) const {
        return data[index];
    }
};

Array arr;
arr[0] = 10;
cout << arr[0] << endl;
```

## インクリメント/デクリメント演算子

```cpp
class Counter {
private:
    int count;

public:
    Counter(int c = 0) : count(c) {}

    // 前置インクリメント（++counter）
    Counter& operator++() {
        ++count;
        return *this;
    }

    // 後置インクリメント（counter++）
    Counter operator++(int) {
        Counter temp = *this;
        ++count;
        return temp;
    }

    int getCount() const { return count; }
};
```

## 関数呼び出し演算子

```cpp
class Multiplier {
private:
    int factor;

public:
    Multiplier(int f) : factor(f) {}

    int operator()(int x) const {
        return x * factor;
    }
};

Multiplier times3(3);
cout << times3(10) << endl;  // 30
```

## オーバーロードできない演算子

以下の演算子はオーバーロードできません：
- `::` (スコープ解決)
- `.` (メンバアクセス)
- `.*` (メンバポインタアクセス)
- `?:` (三項演算子)
- `sizeof`
- `typeid`

## 実践例

`operators.cpp` には以下の例が含まれています：
1. ベクトルクラスの演算子オーバーロード
2. 複素数クラスの四則演算
3. 文字列クラスの演算子
4. 日付クラスの比較演算子
5. カウンタクラスのインクリメント演算子

## 演習問題

`exercises.cpp` で以下を実装してください：

### 演習1: 分数クラス
分数の計算をサポートする Fraction クラスを作成してください。

### 演習2: 行列クラス
2x2行列の演算をサポートする Matrix2x2 クラスを作成してください。

### 演習3: 時間クラス
時刻を扱う Time クラスを作成してください。

## ビルド方法

```bash
cd lesson15_operators
mkdir build
cd build
cmake ..
make
./operators_demo
./exercises
```

## 次のステップ

これでオブジェクト指向編（Lesson 11-15）が完了しました！
Lesson 16からはSTLコンテナ編を学び、C++の強力な標準ライブラリを使いこなします。
