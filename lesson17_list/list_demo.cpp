#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

int main() {
    cout << "=== Lesson 17: list と forward_list ===" << endl << endl;

    // list の基本操作
    cout << "【list】" << endl;
    list<int> lst = {10, 20, 30, 40, 50};

    lst.push_front(5);
    lst.push_back(60);

    cout << "要素: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;

    // 中間への挿入
    auto it = lst.begin();
    advance(it, 3);
    lst.insert(it, 25);

    cout << "挿入後: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl;

    // 値を削除
    lst.remove(30);
    cout << "削除後: ";
    for (int x : lst) {
        cout << x << " ";
    }
    cout << endl << endl;

    // forward_list
    cout << "【forward_list】" << endl;
    forward_list<int> flst = {1, 2, 3, 4, 5};

    flst.push_front(0);

    cout << "要素: ";
    for (int x : flst) {
        cout << x << " ";
    }
    cout << endl;

    // list のソート
    cout << endl << "【list のソート】" << endl;
    list<int> numbers = {42, 17, 93, 8, 65};
    cout << "ソート前: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    numbers.sort();
    cout << "ソート後: ";
    for (int x : numbers) cout << x << " ";
    cout << endl;

    return 0;
}
