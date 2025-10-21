# Lesson 21: unordered_set と unordered_map

## 学習目標
- unordered_set の使い方を学ぶ
- unordered_map の使い方を学ぶ
- ハッシュテーブルと木構造の違いを理解する

## unordered_set（ハッシュセット）

```cpp
#include <unordered_set>

unordered_set<int> us = {3, 1, 4, 1, 5};
us.insert(9);

// O(1) の検索
if (us.find(4) != us.end()) {
    cout << "見つかりました" << endl;
}
```

## unordered_map（ハッシュマップ）

```cpp
#include <unordered_map>

unordered_map<string, int> um;
um["key1"] = 100;
um["key2"] = 200;

// O(1) の検索
int value = um["key1"];
```

## set/map との違い

- **unordered**: ハッシュテーブル、O(1)検索、順序なし
- **ordered (set/map)**: 木構造、O(log n)検索、ソート済み
