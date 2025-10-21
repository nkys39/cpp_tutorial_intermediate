#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// ========================================
// 例1: ベクトルクラス（2D）
// ========================================
class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // 算術演算子
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // 比較演算子
    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }

    // ストリーム演算子
    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    double length() const {
        return sqrt(x * x + y * y);
    }
};

// ========================================
// 例2: 複素数クラス
// ========================================
class Complex {
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 算術演算子
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex(
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        );
    }

    // ストリーム演算子
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << "+";
        os << c.imag << "i";
        return os;
    }
};

// ========================================
// 例3: カウンタクラス
// ========================================
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

    // 前置デクリメント（--counter）
    Counter& operator--() {
        --count;
        return *this;
    }

    // 後置デクリメント（counter--）
    Counter operator--(int) {
        Counter temp = *this;
        --count;
        return temp;
    }

    friend ostream& operator<<(ostream& os, const Counter& c) {
        os << c.count;
        return os;
    }
};

// ========================================
// 例4: 日付クラス
// ========================================
class Date {
private:
    int year, month, day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}

    // 比較演算子
    bool operator==(const Date& other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Date& other) const {
        return other < *this;
    }

    bool operator<=(const Date& other) const {
        return !(other < *this);
    }

    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    // ストリーム演算子
    friend ostream& operator<<(ostream& os, const Date& d) {
        os << d.year << "/" << d.month << "/" << d.day;
        return os;
    }
};

// ========================================
// 例5: 文字列クラス（簡易版）
// ========================================
class MyString {
private:
    string data;

public:
    MyString(const string& s = "") : data(s) {}

    // 連結演算子
    MyString operator+(const MyString& other) const {
        return MyString(data + other.data);
    }

    // 代入演算子
    MyString& operator+=(const MyString& other) {
        data += other.data;
        return *this;
    }

    // 添字演算子
    char& operator[](int index) {
        return data[index];
    }

    const char& operator[](int index) const {
        return data[index];
    }

    // 比較演算子
    bool operator==(const MyString& other) const {
        return data == other.data;
    }

    // ストリーム演算子
    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << s.data;
        return os;
    }

    int length() const {
        return data.length();
    }
};

// ========================================
// 例6: 配列クラス
// ========================================
class IntArray {
private:
    int* data;
    int size;

public:
    IntArray(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
    }

    ~IntArray() {
        delete[] data;
    }

    // コピーコンストラクタ
    IntArray(const IntArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // コピー代入演算子
    IntArray& operator=(const IntArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // 添字演算子
    int& operator[](int index) {
        return data[index];
    }

    const int& operator[](int index) const {
        return data[index];
    }

    // ストリーム演算子
    friend ostream& operator<<(ostream& os, const IntArray& arr) {
        os << "[";
        for (int i = 0; i < arr.size; i++) {
            os << arr.data[i];
            if (i < arr.size - 1) os << ", ";
        }
        os << "]";
        return os;
    }

    int getSize() const { return size; }
};

// ========================================
// メイン関数
// ========================================
int main() {
    cout << "=== Lesson 15: 演算子オーバーロード ===" << endl << endl;

    // 例1: ベクトルクラス
    cout << "【例1】ベクトルクラス" << endl;
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);
    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;
    Vector2D v5 = v1 * 2;

    cout << "v1 = " << v1 << ", 長さ = " << v1.length() << endl;
    cout << "v2 = " << v2 << ", 長さ = " << v2.length() << endl;
    cout << "v1 + v2 = " << v3 << endl;
    cout << "v1 - v2 = " << v4 << endl;
    cout << "v1 * 2 = " << v5 << endl;
    cout << "v1 == v2? " << (v1 == v2 ? "はい" : "いいえ") << endl;
    cout << endl;

    // 例2: 複素数クラス
    cout << "【例2】複素数クラス" << endl;
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    Complex c5 = c1 * c2;
    Complex c6 = c1 / c2;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c3 << endl;
    cout << "c1 - c2 = " << c4 << endl;
    cout << "c1 * c2 = " << c5 << endl;
    cout << "c1 / c2 = " << c6 << endl;
    cout << endl;

    // 例3: カウンタクラス
    cout << "【例3】カウンタクラス" << endl;
    Counter cnt(10);
    cout << "初期値: " << cnt << endl;
    cout << "++cnt: " << ++cnt << endl;
    cout << "cnt++: " << cnt++ << endl;
    cout << "現在値: " << cnt << endl;
    cout << "--cnt: " << --cnt << endl;
    cout << "cnt--: " << cnt-- << endl;
    cout << "現在値: " << cnt << endl;
    cout << endl;

    // 例4: 日付クラス
    cout << "【例4】日付クラス" << endl;
    Date d1(2024, 12, 25);
    Date d2(2024, 12, 31);
    Date d3(2024, 12, 25);

    cout << "d1 = " << d1 << endl;
    cout << "d2 = " << d2 << endl;
    cout << "d3 = " << d3 << endl;
    cout << "d1 == d3? " << (d1 == d3 ? "はい" : "いいえ") << endl;
    cout << "d1 < d2? " << (d1 < d2 ? "はい" : "いいえ") << endl;
    cout << "d1 > d2? " << (d1 > d2 ? "はい" : "いいえ") << endl;
    cout << endl;

    // 例5: 文字列クラス
    cout << "【例5】文字列クラス" << endl;
    MyString s1("Hello");
    MyString s2(" World");
    MyString s3 = s1 + s2;

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s1 + s2 = " << s3 << endl;
    cout << "s3[0] = " << s3[0] << endl;

    s1 += s2;
    cout << "s1 += s2: " << s1 << endl;
    cout << endl;

    // 例6: 配列クラス
    cout << "【例6】配列クラス" << endl;
    IntArray arr(5);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    cout << "arr = " << arr << endl;

    IntArray arr2 = arr;  // コピーコンストラクタ
    arr2[0] = 99;
    cout << "arr = " << arr << endl;
    cout << "arr2 = " << arr2 << endl;

    return 0;
}
