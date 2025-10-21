#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    cout << "=== Lesson 22: STLアルゴリズム ===" << endl << endl;

    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};

    // ソート
    cout << "【sort】" << endl;
    sort(v.begin(), v.end());
    cout << "昇順: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    sort(v.begin(), v.end(), greater<int>());
    cout << "降順: ";
    for (int x : v) cout << x << " ";
    cout << endl << endl;

    // 検索
    cout << "【find】" << endl;
    auto it = find(v.begin(), v.end(), 5);
    if (it != v.end()) {
        cout << "5が見つかりました（位置: " << distance(v.begin(), it) << "）" << endl;
    }
    cout << endl;

    // カウント
    cout << "【count】" << endl;
    cout << "5の個数: " << count(v.begin(), v.end(), 5) << endl << endl;

    // 最大・最小
    cout << "【min_element / max_element】" << endl;
    auto minIt = min_element(v.begin(), v.end());
    auto maxIt = max_element(v.begin(), v.end());
    cout << "最小値: " << *minIt << endl;
    cout << "最大値: " << *maxIt << endl << endl;

    // 変換
    cout << "【transform】" << endl;
    vector<int> doubled(v.size());
    transform(v.begin(), v.end(), doubled.begin(), [](int x) { return x * 2; });
    cout << "2倍: ";
    for (int x : doubled) cout << x << " ";
    cout << endl << endl;

    // 集計
    cout << "【accumulate】" << endl;
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "合計: " << sum << endl;

    int product = accumulate(v.begin(), v.end(), 1, [](int a, int b) { return a * b; });
    cout << "積: " << product << endl << endl;

    // フィルタリング
    cout << "【remove_if】" << endl;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto newEnd = remove_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
    nums.erase(newEnd, nums.end());
    cout << "奇数のみ: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
