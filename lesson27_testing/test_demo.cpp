#include <iostream>
#include <cassert>
using namespace std;

// テスト対象の関数
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// 簡易テストマクロ
#define ASSERT_EQ(a, b) \
    if ((a) != (b)) { \
        cout << "❌ FAILED: " << #a << " != " << #b \
             << " (expected " << (b) << ", got " << (a) << ")" << endl; \
        return false; \
    } else { \
        cout << "✓ PASSED: " << #a << " == " << #b << endl; \
    }

bool test_add() {
    cout << "\n【test_add】" << endl;
    ASSERT_EQ(add(2, 3), 5);
    ASSERT_EQ(add(-1, 1), 0);
    ASSERT_EQ(add(0, 0), 0);
    return true;
}

bool test_multiply() {
    cout << "\n【test_multiply】" << endl;
    ASSERT_EQ(multiply(2, 3), 6);
    ASSERT_EQ(multiply(-2, 3), -6);
    ASSERT_EQ(multiply(0, 5), 0);
    return true;
}

int main() {
    cout << "=== Lesson 27: 単体テスト ===" << endl;

    int passed = 0;
    int total = 0;

    total++; if (test_add()) passed++;
    total++; if (test_multiply()) passed++;

    cout << "\n========================================" << endl;
    cout << "結果: " << passed << "/" << total << " テスト成功" << endl;

    return (passed == total) ? 0 : 1;
}
