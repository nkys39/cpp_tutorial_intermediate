#include <iostream>
#include "mylib.h"

using namespace std;

int main() {
    cout << "=== Lesson 28: ライブラリの作成 ===" << endl << endl;

    MyLib::print_info();

    cout << "10 + 5 = " << MyLib::add(10, 5) << endl;
    cout << "10 - 5 = " << MyLib::subtract(10, 5) << endl;

    return 0;
}
