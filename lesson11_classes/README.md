# Lesson 11: クラスとオブジェクト基礎

## 学習目標
- クラスの定義方法を理解する
- メンバ変数とメンバ関数の概念を学ぶ
- アクセス指定子（public, private, protected）を理解する
- オブジェクトの生成と使用方法を学ぶ

## クラスとは？

クラスは、データ（メンバ変数）と機能（メンバ関数）をまとめた設計図です。

```cpp
class Rectangle {
public:
    // メンバ変数
    double width;
    double height;

    // メンバ関数
    double getArea() {
        return width * height;
    }
};
```

## アクセス指定子

### public
- クラス外部からアクセス可能

### private
- クラス内部からのみアクセス可能（デフォルト）

### protected
- クラス内部と派生クラスからアクセス可能

```cpp
class BankAccount {
private:
    double balance;  // 外部から直接変更できない

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() {
        return balance;
    }
};
```

## オブジェクトの生成

```cpp
Rectangle rect;
rect.width = 10.0;
rect.height = 5.0;
cout << "面積: " << rect.getArea() << endl;
```

## 実践例

`classes.cpp` には以下の例が含まれています：
1. 基本的なクラス定義
2. アクセス指定子の使用
3. ゲッター/セッターメソッド
4. 複数のオブジェクトの操作

## 演習問題

`exercises.cpp` で以下を実装してください：

### 演習1: 学生クラス
名前、学年、成績を管理する `Student` クラスを作成してください。

### 演習2: 銀行口座クラス
口座番号、残高、入出金機能を持つ `BankAccount` クラスを作成してください。

### 演習3: 図書クラス
タイトル、著者、出版年を管理する `Book` クラスを作成してください。

## ビルド方法

```bash
cd lesson11_classes
mkdir build
cd build
cmake ..
make
./classes_demo
./exercises
```

## 次のステップ

Lesson 12では、コンストラクタとデストラクタを学び、オブジェクトの初期化と後処理を理解します。
