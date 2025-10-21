#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <chrono>
using namespace std;

int main() {
    cout << "=== Lesson 21: unordered_set と unordered_map ===" << endl << endl;

    // unordered_set
    cout << "【unordered_set】" << endl;
    unordered_set<int> us = {3, 1, 4, 1, 5, 9};

    cout << "要素（順序は保証されない）: ";
    for (int x : us) {
        cout << x << " ";
    }
    cout << endl;

    us.insert(2);
    cout << "サイズ: " << us.size() << endl;

    // O(1) 検索
    if (us.find(5) != us.end()) {
        cout << "5が見つかりました（O(1)）" << endl;
    }
    cout << endl;

    // unordered_map
    cout << "【unordered_map】" << endl;
    unordered_map<string, int> um;

    um["apple"] = 100;
    um["banana"] = 200;
    um["cherry"] = 150;

    cout << "apple: " << um["apple"] << endl;

    for (auto& pair : um) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << endl;

    // パフォーマンス比較
    cout << "【パフォーマンス比較】" << endl;
    const int N = 100000;

    // set vs unordered_set の挿入
    set<int> s;
    unordered_set<int> us2;

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        s.insert(i);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration_set = chrono::duration_cast<chrono::milliseconds>(end - start);

    start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        us2.insert(i);
    }
    end = chrono::high_resolution_clock::now();
    auto duration_uset = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "set の挿入時間: " << duration_set.count() << "ms" << endl;
    cout << "unordered_set の挿入時間: " << duration_uset.count() << "ms" << endl;

    return 0;
}
