# Lesson 12: コンストラクタとデストラクタ

## 学習目標
- コンストラクタの役割と種類を理解する
- デストラクタの役割を理解する
- 初期化リストの使い方を学ぶ
- コピーコンストラクタを理解する

## コンストラクタとは？

コンストラクタは、オブジェクトが生成されるときに**自動的に呼び出される**特別なメンバ関数です。

### 特徴
- クラス名と同じ名前
- 戻り値の型を持たない
- オブジェクトの初期化に使用

## コンストラクタの種類

### 1. デフォルトコンストラクタ

引数を持たないコンストラクタ：

```cpp
class Point {
private:
    int x, y;

public:
    // デフォルトコンストラクタ
    Point() {
        x = 0;
        y = 0;
        cout << "デフォルトコンストラクタが呼ばれました" << endl;
    }
};

Point p;  // デフォルトコンストラクタが呼ばれる
```

### 2. パラメータ付きコンストラクタ

引数を受け取って初期化するコンストラクタ：

```cpp
class Point {
private:
    int x, y;

public:
    // パラメータ付きコンストラクタ
    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
        cout << "パラメータ付きコンストラクタが呼ばれました" << endl;
    }
};

Point p(10, 20);  // パラメータ付きコンストラクタが呼ばれる
```

### 3. 初期化リスト

メンバ変数を効率的に初期化する方法：

```cpp
class Point {
private:
    int x, y;

public:
    // 初期化リストを使用
    Point(int xVal, int yVal) : x(xVal), y(yVal) {
        cout << "初期化リストで初期化しました" << endl;
    }
};
```

**初期化リストの利点：**
- const メンバ変数を初期化できる
- 参照型メンバ変数を初期化できる
- より効率的（代入ではなく初期化）

### 4. コピーコンストラクタ

既存のオブジェクトから新しいオブジェクトを作成：

```cpp
class Point {
private:
    int x, y;

public:
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}

    // コピーコンストラクタ
    Point(const Point& other) : x(other.x), y(other.y) {
        cout << "コピーコンストラクタが呼ばれました" << endl;
    }
};

Point p1(10, 20);
Point p2(p1);  // コピーコンストラクタが呼ばれる
Point p3 = p1; // これもコピーコンストラクタが呼ばれる
```

## デストラクタとは？

デストラクタは、オブジェクトが破棄されるときに**自動的に呼び出される**特別なメンバ関数です。

### 特徴
- クラス名の前に `~` を付けた名前
- 引数を持たない
- 戻り値の型を持たない
- リソースの解放に使用

```cpp
class DynamicArray {
private:
    int* data;
    int size;

public:
    // コンストラクタ
    DynamicArray(int s) : size(s) {
        data = new int[size];
        cout << "配列を確保しました" << endl;
    }

    // デストラクタ
    ~DynamicArray() {
        delete[] data;
        cout << "配列を解放しました" << endl;
    }
};
```

## コンストラクタのデフォルト引数

```cpp
class Rectangle {
private:
    double width, height;

public:
    // デフォルト引数を持つコンストラクタ
    Rectangle(double w = 1.0, double h = 1.0) : width(w), height(h) {}
};

Rectangle r1;           // width=1.0, height=1.0
Rectangle r2(5.0);      // width=5.0, height=1.0
Rectangle r3(5.0, 3.0); // width=5.0, height=3.0
```

## 実践例

`constructors.cpp` には以下の例が含まれています：
1. 各種コンストラクタの動作確認
2. 初期化リストの使用
3. デストラクタの動作確認
4. 実用的なクラス例

## 演習問題

`exercises.cpp` で以下を実装してください：

### 演習1: 日付クラス
年月日を管理する `Date` クラスを作成してください。
- デフォルトコンストラクタ（今日の日付）
- パラメータ付きコンストラクタ
- 日付の表示機能

### 演習2: 文字列クラス
動的メモリを使用する `MyString` クラスを作成してください。
- コンストラクタで文字列を確保
- デストラクタでメモリ解放
- コピーコンストラクタ

### 演習3: カウンタクラス
オブジェクトの生成数をカウントする `Counter` クラスを作成してください。

## ビルド方法

```bash
cd lesson12_constructors
mkdir build
cd build
cmake ..
make
./constructors_demo
./exercises
```

## 次のステップ

Lesson 13では、継承とポリモーフィズムを学び、オブジェクト指向プログラミングの強力な機能を理解します。
