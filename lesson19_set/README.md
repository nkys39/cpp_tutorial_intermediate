# Lesson 19: set と multiset

## 学習目標
- set（順序付き集合）の使い方を学ぶ
- multiset の使い方を学ぶ
- 集合演算を理解する

## set

重複を許さない順序付き集合：

```cpp
#include <set>

set<int> s = {3, 1, 4, 1, 5};  // {1, 3, 4, 5}（重複削除・ソート済み）
s.insert(2);
s.erase(3);

if (s.find(4) != s.end()) {
    cout << "4が見つかりました" << endl;
}
```

## multiset

重複を許す順序付き集合：

```cpp
multiset<int> ms = {1, 2, 2, 3, 3, 3};
cout << ms.count(3) << endl;  // 3
```
