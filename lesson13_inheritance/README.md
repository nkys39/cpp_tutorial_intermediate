# Lesson 13: 継承とポリモーフィズム

## 学習目標
- 継承の概念と使い方を理解する
- 基底クラスと派生クラスの関係を学ぶ
- virtual関数とポリモーフィズムを理解する
- オーバーライドの使い方を学ぶ
- 抽象クラスとインターフェースの概念を学ぶ

## 継承とは？

継承は、既存のクラス（基底クラス）の機能を引き継いで、新しいクラス（派生クラス）を作成する仕組みです。

### 基本的な構文

```cpp
class Animal {  // 基底クラス
protected:
    string name;

public:
    void setName(string n) { name = n; }
    void eat() { cout << name << " is eating" << endl; }
};

class Dog : public Animal {  // 派生クラス
public:
    void bark() { cout << name << " is barking" << endl; }
};

Dog dog;
dog.setName("ポチ");
dog.eat();   // 継承したメソッド
dog.bark();  // 独自のメソッド
```

## 継承のアクセス指定子

### public 継承
- 基底クラスのpublicメンバ → 派生クラスでpublic
- 基底クラスのprotectedメンバ → 派生クラスでprotected

### protected 継承
- 基底クラスのpublicメンバ → 派生クラスでprotected
- 基底クラスのprotectedメンバ → 派生クラスでprotected

### private 継承
- 基底クラスのpublicメンバ → 派生クラスでprivate
- 基底クラスのprotectedメンバ → 派生クラスでprivate

**通常は public 継承を使用します。**

## コンストラクタと継承

派生クラスのコンストラクタは、基底クラスのコンストラクタを呼び出す必要があります。

```cpp
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) : name(n), age(a) {}
};

class Student : public Person {
private:
    int studentId;

public:
    // 基底クラスのコンストラクタを呼び出す
    Student(string n, int a, int id)
        : Person(n, a), studentId(id) {}
};
```

## ポリモーフィズム

ポリモーフィズム（多態性）は、同じインターフェースで異なる動作を実現する仕組みです。

### virtual 関数

```cpp
class Shape {
public:
    virtual double getArea() {
        return 0.0;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    // オーバーライド
    double getArea() override {
        return 3.14159 * radius * radius;
    }
};

Shape* shape = new Circle(5.0);
cout << shape->getArea();  // Circle::getArea() が呼ばれる
```

### override キーワード

`override` を付けることで、意図したオーバーライドができているか確認できます（C++11以降）。

## 純粋仮想関数と抽象クラス

純粋仮想関数を持つクラスは**抽象クラス**となり、インスタンス化できません。

```cpp
class Shape {
public:
    // 純粋仮想関数
    virtual double getArea() = 0;
    virtual void draw() = 0;
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // 純粋仮想関数を実装
    double getArea() override {
        return width * height;
    }

    void draw() override {
        cout << "Drawing rectangle" << endl;
    }
};

// Shape shape;  // エラー：抽象クラスはインスタンス化できない
Rectangle rect(5, 3);  // OK
```

## 仮想デストラクタ

基底クラスのポインタで派生クラスのオブジェクトを削除する場合、デストラクタをvirtualにする必要があります。

```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived destructor" << endl;
    }
};

Base* obj = new Derived();
delete obj;  // Derived と Base の両方のデストラクタが呼ばれる
```

## 多重継承

C++では複数のクラスから継承できます（ただし、複雑になりがちなので注意）。

```cpp
class Flyable {
public:
    virtual void fly() = 0;
};

class Swimmable {
public:
    virtual void swim() = 0;
};

class Duck : public Flyable, public Swimmable {
public:
    void fly() override {
        cout << "Duck is flying" << endl;
    }

    void swim() override {
        cout << "Duck is swimming" << endl;
    }
};
```

## 実践例

`inheritance.cpp` には以下の例が含まれています：
1. 基本的な継承
2. ポリモーフィズムの動作
3. 抽象クラスの使用
4. 仮想デストラクタの重要性
5. 多重継承の例

## 演習問題

`exercises.cpp` で以下を実装してください：

### 演習1: 従業員管理システム
基底クラス `Employee` と派生クラス `Manager`, `Engineer` を作成してください。

### 演習2: 図形クラス階層
抽象クラス `Shape` と派生クラス `Circle`, `Rectangle`, `Triangle` を作成してください。

### 演習3: 動物クラス
基底クラス `Animal` と派生クラス `Dog`, `Cat`, `Bird` を作成してください。

## ビルド方法

```bash
cd lesson13_inheritance
mkdir build
cd build
cmake ..
make
./inheritance_demo
./exercises
```

## 次のステップ

Lesson 14では、名前空間と列挙型を学び、コードの整理とスコープ管理を理解します。
