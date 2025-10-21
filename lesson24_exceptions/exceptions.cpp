#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// カスタム例外
class DivideByZeroException : public exception {
public:
    const char* what() const noexcept override {
        return "ゼロ除算エラー";
    }
};

double divide(double a, double b) {
    if (b == 0) {
        throw DivideByZeroException();
    }
    return a / b;
}

int main() {
    cout << "=== Lesson 24: 例外処理 ===" << endl << endl;

    // 基本的な例外処理
    cout << "【基本的な例外処理】" << endl;
    try {
        cout << "10 / 2 = " << divide(10, 2) << endl;
        cout << "10 / 0 = " << divide(10, 0) << endl;  // 例外発生
        cout << "この行は実行されません" << endl;
    } catch (const DivideByZeroException& e) {
        cout << "例外をキャッチ: " << e.what() << endl;
    }
    cout << endl;

    // 標準例外
    cout << "【標準例外】" << endl;
    try {
        string s = "Hello";
        cout << s.at(10) << endl;  // out_of_range 例外
    } catch (const out_of_range& e) {
        cout << "out_of_range: " << e.what() << endl;
    }
    cout << endl;

    // 複数の catch
    cout << "【複数のcatch】" << endl;
    try {
        throw runtime_error("実行時エラー");
    } catch (const logic_error& e) {
        cout << "logic_error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "runtime_error: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "exception: " << e.what() << endl;
    }

    return 0;
}
