#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    cout << "=== Lesson 19: set と multiset ===" << endl << endl;

    // set の基本操作
    cout << "【set】" << endl;
    set<int> s = {3, 1, 4, 1, 5, 9, 2, 6};

    cout << "要素（自動的にソート・重複削除）: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;

    s.insert(7);
    s.insert(1);  // 既に存在するので追加されない

    cout << "サイズ: " << s.size() << endl;

    // 検索
    if (s.find(5) != s.end()) {
        cout << "5が見つかりました" << endl;
    }

    s.erase(4);
    cout << "4を削除後: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl << endl;

    // multiset
    cout << "【multiset】" << endl;
    multiset<int> ms = {1, 2, 2, 3, 3, 3, 4};

    cout << "要素: ";
    for (int x : ms) {
        cout << x << " ";
    }
    cout << endl;

    cout << "3の個数: " << ms.count(3) << endl;

    ms.insert(2);
    cout << "2を追加後の2の個数: " << ms.count(2) << endl << endl;

    // 実用例：重複チェック
    cout << "【実用例】重複検出" << endl;
    vector<int> numbers = {1, 2, 3, 2, 4, 5, 3, 6};
    set<int> unique(numbers.begin(), numbers.end());

    cout << "元のサイズ: " << numbers.size() << endl;
    cout << "ユニークな要素数: " << unique.size() << endl;

    return 0;
}
