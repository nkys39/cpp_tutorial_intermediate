#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    cout << "=== Lesson 20: map と multimap ===" << endl << endl;

    // map の基本操作
    cout << "【map】" << endl;
    map<string, int> ages;

    ages["Alice"] = 25;
    ages["Bob"] = 30;
    ages["Charlie"] = 28;

    cout << "Alice の年齢: " << ages["Alice"] << endl;

    // イテレータで走査
    cout << "\n全員の年齢:" << endl;
    for (auto& pair : ages) {
        cout << pair.first << ": " << pair.second << "歳" << endl;
    }

    // 検索
    if (ages.find("Bob") != ages.end()) {
        cout << "\nBob が見つかりました" << endl;
    }

    // 削除
    ages.erase("Charlie");
    cout << "\nCharlie削除後のサイズ: " << ages.size() << endl << endl;

    // multimap
    cout << "【multimap】" << endl;
    multimap<string, int> scores;

    scores.insert({"Alice", 85});
    scores.insert({"Alice", 92});
    scores.insert({"Bob", 78});
    scores.insert({"Alice", 88});

    cout << "Alice の全スコア: ";
    auto range = scores.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << endl << endl;

    // 実用例：単語カウント
    cout << "【実用例】単語カウント" << endl;
    string text = "apple banana apple cherry banana apple";
    map<string, int> wordCount;

    // 簡易的な単語分割（スペース区切り）
    string word;
    for (char c : text + " ") {
        if (c == ' ') {
            if (!word.empty()) {
                wordCount[word]++;
                word.clear();
            }
        } else {
            word += c;
        }
    }

    for (auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << "回" << endl;
    }

    return 0;
}
