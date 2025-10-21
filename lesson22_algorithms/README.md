# Lesson 22: STLアルゴリズム

## 学習目標
- STL標準アルゴリズムの使い方を学ぶ
- sort, find, count などの基本アルゴリズムを理解する
- transform, accumulate などの応用アルゴリズムを学ぶ

## 主要なアルゴリズム

### ソート
```cpp
#include <algorithm>

vector<int> v = {3, 1, 4, 1, 5};
sort(v.begin(), v.end());  // 昇順
sort(v.begin(), v.end(), greater<int>());  // 降順
```

### 検索
```cpp
auto it = find(v.begin(), v.end(), 4);
int count = count(v.begin(), v.end(), 1);
```

### 変換
```cpp
transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 2; });
```

### 集計
```cpp
#include <numeric>

int sum = accumulate(v.begin(), v.end(), 0);
```
