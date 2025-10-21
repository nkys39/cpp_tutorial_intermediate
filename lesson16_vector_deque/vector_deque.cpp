#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    cout << "=== Lesson 16: vector と deque ===" << endl << endl;

    // vector の基本操作
    cout << "【vector】" << endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "サイズ: " << v.size() << endl;
    cout << "要素: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    // vector の初期化
    vector<int> v2 = {1, 2, 3, 4, 5};
    vector<int> v3(10, 0);  // 10個の0

    // vector の便利な操作
    v2.insert(v2.begin() + 2, 99);  // 2番目に挿入
    v2.erase(v2.begin());  // 最初の要素を削除

    cout << "変更後: ";
    for (int x : v2) {
        cout << x << " ";
    }
    cout << endl << endl;

    // deque の基本操作
    cout << "【deque】" << endl;
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_front(5);  // 先頭に追加
    d.push_front(1);

    cout << "要素: ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl;

    d.pop_front();
    d.pop_back();

    cout << "削除後: ";
    for (int x : d) {
        cout << x << " ";
    }
    cout << endl << endl;

    // vector を使った実用例
    cout << "【実用例】学生の成績管理" << endl;
    vector<int> scores = {85, 92, 78, 95, 88};

    int sum = 0;
    for (int score : scores) {
        sum += score;
    }
    double average = static_cast<double>(sum) / scores.size();
    cout << "平均点: " << average << endl;

    sort(scores.begin(), scores.end());
    cout << "最低点: " << scores.front() << endl;
    cout << "最高点: " << scores.back() << endl;

    return 0;
}
