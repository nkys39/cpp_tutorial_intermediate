#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "=== Lesson 23: イテレータとラムダ式 ===" << endl << endl;

    // ラムダ式の基本
    cout << "【ラムダ式】" << endl;
    auto add = [](int a, int b) { return a + b; };
    cout << "3 + 4 = " << add(3, 4) << endl << endl;

    // キャプチャ
    cout << "【キャプチャ】" << endl;
    int multiplier = 3;

    auto multiplyBy = [multiplier](int x) { return x * multiplier; };
    cout << "5 * " << multiplier << " = " << multiplyBy(5) << endl;

    // 参照キャプチャ
    int counter = 0;
    auto increment = [&counter]() { counter++; };
    increment();
    increment();
    cout << "Counter: " << counter << endl << endl;

    // ラムダ式とSTLアルゴリズム
    cout << "【ラムダ式とSTL】" << endl;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 偶数をカウント
    int evenCount = count_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    cout << "偶数の個数: " << evenCount << endl;

    // 条件に合う要素を検索
    auto it = find_if(v.begin(), v.end(), [](int x) { return x > 5; });
    if (it != v.end()) {
        cout << "5より大きい最初の要素: " << *it << endl;
    }

    // 全要素を2倍
    for_each(v.begin(), v.end(), [](int& x) { x *= 2; });
    cout << "2倍後: ";
    for (int x : v) cout << x << " ";
    cout << endl << endl;

    // ソート（カスタム比較）
    cout << "【カスタムソート】" << endl;
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6};

    sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    cout << "降順: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
