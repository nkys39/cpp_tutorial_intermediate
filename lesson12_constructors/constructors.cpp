#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ========================================
// 例1: デフォルトコンストラクタとパラメータ付きコンストラクタ
// ========================================
class Point {
private:
    int x, y;

public:
    // デフォルトコンストラクタ
    Point() {
        x = 0;
        y = 0;
        cout << "Point: デフォルトコンストラクタ呼び出し (0, 0)" << endl;
    }

    // パラメータ付きコンストラクタ
    Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
        cout << "Point: パラメータ付きコンストラクタ呼び出し (" << x << ", " << y << ")" << endl;
    }

    void display() {
        cout << "座標: (" << x << ", " << y << ")" << endl;
    }
};

// ========================================
// 例2: 初期化リストの使用
// ========================================
class Rectangle {
private:
    double width, height;
    const int id;  // const メンバ変数

public:
    // 初期化リストを使用（const メンバも初期化可能）
    Rectangle(double w, double h, int i) : width(w), height(h), id(i) {
        cout << "Rectangle: ID " << id << " を作成 (" << width << " x " << height << ")" << endl;
    }

    double getArea() const {
        return width * height;
    }

    void display() const {
        cout << "ID: " << id << ", サイズ: " << width << " x " << height
             << ", 面積: " << getArea() << endl;
    }
};

// ========================================
// 例3: コピーコンストラクタ
// ========================================
class Person {
private:
    string name;
    int age;

public:
    // パラメータ付きコンストラクタ
    Person(string n, int a) : name(n), age(a) {
        cout << "Person: " << name << " を作成（年齢 " << age << "）" << endl;
    }

    // コピーコンストラクタ
    Person(const Person& other) : name(other.name), age(other.age) {
        cout << "Person: " << name << " をコピー作成" << endl;
    }

    void display() const {
        cout << "名前: " << name << ", 年齢: " << age << endl;
    }

    void setName(string n) {
        name = n;
    }
};

// ========================================
// 例4: デストラクタとリソース管理
// ========================================
class DynamicArray {
private:
    int* data;
    int size;

public:
    // コンストラクタ（メモリ確保）
    DynamicArray(int s) : size(s) {
        data = new int[size];
        cout << "DynamicArray: サイズ " << size << " の配列を確保" << endl;

        // 初期化
        for (int i = 0; i < size; i++) {
            data[i] = i * 10;
        }
    }

    // デストラクタ（メモリ解放）
    ~DynamicArray() {
        delete[] data;
        cout << "DynamicArray: サイズ " << size << " の配列を解放" << endl;
    }

    void display() const {
        cout << "配列の内容: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    int getSize() const {
        return size;
    }
};

// ========================================
// 例5: デフォルト引数を持つコンストラクタ
// ========================================
class Box {
private:
    double width, height, depth;

public:
    // デフォルト引数を持つコンストラクタ
    Box(double w = 1.0, double h = 1.0, double d = 1.0)
        : width(w), height(h), depth(d) {
        cout << "Box: " << width << " x " << height << " x " << depth << " を作成" << endl;
    }

    double getVolume() const {
        return width * height * depth;
    }

    void display() const {
        cout << "サイズ: " << width << " x " << height << " x " << depth
             << ", 体積: " << getVolume() << endl;
    }
};

// ========================================
// 例6: コンストラクタの委譲（C++11）
// ========================================
class Student {
private:
    string name;
    int studentId;
    double gpa;

public:
    // メインのコンストラクタ
    Student(string n, int id, double g) : name(n), studentId(id), gpa(g) {
        cout << "Student: " << name << " (ID: " << studentId << ") を作成" << endl;
    }

    // コンストラクタの委譲
    Student(string n, int id) : Student(n, id, 0.0) {
        cout << "  (GPAはデフォルト値0.0)" << endl;
    }

    Student(string n) : Student(n, 0, 0.0) {
        cout << "  (IDとGPAはデフォルト値)" << endl;
    }

    void display() const {
        cout << "学生: " << name << ", ID: " << studentId << ", GPA: " << gpa << endl;
    }
};

// ========================================
// 例7: オブジェクトカウンタ
// ========================================
class ObjectCounter {
private:
    static int objectCount;  // 静的メンバ変数（全オブジェクトで共有）
    int objectId;

public:
    ObjectCounter() : objectId(++objectCount) {
        cout << "ObjectCounter #" << objectId << " を作成（合計: " << objectCount << "）" << endl;
    }

    ~ObjectCounter() {
        cout << "ObjectCounter #" << objectId << " を破棄（残り: " << --objectCount << "）" << endl;
    }

    static int getCount() {
        return objectCount;
    }
};

// 静的メンバ変数の定義
int ObjectCounter::objectCount = 0;

// ========================================
// メイン関数
// ========================================
int main() {
    cout << "=== Lesson 12: コンストラクタとデストラクタ ===" << endl << endl;

    // 例1: デフォルトとパラメータ付きコンストラクタ
    cout << "【例1】コンストラクタの種類" << endl;
    Point p1;           // デフォルトコンストラクタ
    Point p2(10, 20);   // パラメータ付きコンストラクタ
    p1.display();
    p2.display();
    cout << endl;

    // 例2: 初期化リスト
    cout << "【例2】初期化リスト" << endl;
    Rectangle rect1(5.0, 3.0, 1);
    Rectangle rect2(10.0, 7.0, 2);
    rect1.display();
    rect2.display();
    cout << endl;

    // 例3: コピーコンストラクタ
    cout << "【例3】コピーコンストラクタ" << endl;
    Person person1("山田太郎", 25);
    Person person2(person1);  // コピーコンストラクタ
    Person person3 = person1; // これもコピーコンストラクタ

    person2.setName("佐藤花子");
    person1.display();
    person2.display();
    person3.display();
    cout << endl;

    // 例4: デストラクタとリソース管理
    cout << "【例4】デストラクタ（スコープ内）" << endl;
    {
        DynamicArray arr(5);
        arr.display();
        cout << "スコープ終了..." << endl;
    }  // ここでデストラクタが呼ばれる
    cout << "スコープ外" << endl << endl;

    // 例5: デフォルト引数
    cout << "【例5】デフォルト引数" << endl;
    Box box1;              // すべてデフォルト
    Box box2(5.0);         // width のみ指定
    Box box3(5.0, 3.0);    // width, height 指定
    Box box4(5.0, 3.0, 2.0); // すべて指定
    box1.display();
    box2.display();
    box3.display();
    box4.display();
    cout << endl;

    // 例6: コンストラクタの委譲
    cout << "【例6】コンストラクタの委譲" << endl;
    Student s1("田中一郎", 1001, 3.5);
    Student s2("鈴木二郎", 1002);
    Student s3("高橋三郎");
    s1.display();
    s2.display();
    s3.display();
    cout << endl;

    // 例7: オブジェクトカウンタ
    cout << "【例7】オブジェクトカウンタ" << endl;
    {
        ObjectCounter obj1;
        ObjectCounter obj2;
        {
            ObjectCounter obj3;
            cout << "現在のオブジェクト数: " << ObjectCounter::getCount() << endl;
        }
        cout << "内側のスコープ終了後: " << ObjectCounter::getCount() << endl;
    }
    cout << "すべてのスコープ終了後: " << ObjectCounter::getCount() << endl;

    return 0;
}
