#include <iostream>
using namespace std;

// TODO: 以下の演習を実装してください

// ========================================
// 演習1: 分数クラス
// ========================================
// Fraction クラスを作成し、以下の演算子をオーバーロードしてください：
// - operator+, operator-, operator*, operator/
// - operator==, operator<
// - operator<<
// - 約分機能（gcd関数を使用）

class Fraction {
    // ここに実装
};

// ========================================
// 演習2: 2x2行列クラス
// ========================================
// Matrix2x2 クラスを作成し、以下の演算子をオーバーロードしてください：
// - operator+ (行列の加算)
// - operator* (行列の乗算)
// - operator* (スカラー倍)
// - operator<<

class Matrix2x2 {
    // ここに実装
};

// ========================================
// 演習3: 時間クラス
// ========================================
// Time クラスを作成し、以下の演算子をオーバーロードしてください：
// - operator+ (時間の加算)
// - operator- (時間の減算)
// - operator<, operator>
// - operator<<

class Time {
    // ここに実装
};

// テスト関数
void testFraction() {
    cout << "=== 演習1: 分数クラスのテスト ===" << endl;
    // TODO: Fraction クラスをテスト
    cout << endl;
}

void testMatrix() {
    cout << "=== 演習2: 行列クラスのテスト ===" << endl;
    // TODO: Matrix2x2 クラスをテスト
    cout << endl;
}

void testTime() {
    cout << "=== 演習3: 時間クラスのテスト ===" << endl;
    // TODO: Time クラスをテスト
    cout << endl;
}

int main() {
    cout << "=== Lesson 15: 演習問題 ===" << endl << endl;

    testFraction();
    testMatrix();
    testTime();

    cout << "すべての演習を完了しました！" << endl;

    return 0;
}
