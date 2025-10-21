#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    cout << "=== Lesson 26: ヘッダとソースの分離 ===" << endl << endl;

    Calculator calc;

    cout << "10 + 5 = " << calc.add(10, 5) << endl;
    cout << "10 - 5 = " << calc.subtract(10, 5) << endl;
    cout << "10 * 5 = " << calc.multiply(10, 5) << endl;
    cout << "10 / 5 = " << calc.divide(10, 5) << endl;

    try {
        cout << "10 / 0 = " << calc.divide(10, 0) << endl;
    } catch (const exception& e) {
        cout << "エラー: " << e.what() << endl;
    }

    return 0;
}
