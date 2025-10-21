# Lesson 16: vector と deque

## 学習目標
- STLコンテナの基本を理解する
- vector の使い方を学ぶ
- deque の使い方と vector との違いを理解する
- 適切なコンテナの選び方を学ぶ

## vector（動的配列）

`vector` は動的にサイズ変更できる配列です。

### 基本操作

```cpp
#include <vector>

vector<int> v;
v.push_back(10);  // 末尾に追加
v.push_back(20);
v.push_back(30);

cout << v[0] << endl;  // 10
cout << v.size() << endl;  // 3

v.pop_back();  // 末尾から削除
```

### イテレータ

```cpp
for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}

// 範囲ベースfor（C++11）
for (int x : v) {
    cout << x << " ";
}
```

## deque（両端キュー）

`deque` は両端での挿入・削除が高速なコンテナです。

```cpp
#include <deque>

deque<int> d;
d.push_back(10);   // 末尾に追加
d.push_front(5);   // 先頭に追加
d.pop_front();     // 先頭から削除
```

## ビルド方法

```bash
cd lesson16_vector_deque
mkdir build && cd build
cmake .. && make
./vector_deque_demo
./exercises
```
