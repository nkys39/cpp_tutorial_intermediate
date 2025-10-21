# Lesson 17: list と forward_list

## 学習目標
- list（双方向リスト）の使い方を学ぶ
- forward_list（単方向リスト）の使い方を学ぶ
- vector との違いを理解する

## list（双方向リスト）

```cpp
#include <list>

list<int> lst = {10, 20, 30};
lst.push_front(5);  // 先頭に追加
lst.push_back(40);  // 末尾に追加
lst.remove(20);     // 値を削除
```

### 特徴
- 中間への挿入・削除が O(1)
- ランダムアクセス不可（[]使えない）
- 双方向イテレータ

## forward_list（単方向リスト）

```cpp
#include <forward_list>

forward_list<int> flst = {1, 2, 3};
flst.push_front(0);  // 先頭に追加のみ
```

## ビルド方法

```bash
cd lesson17_list
mkdir build && cd build
cmake .. && make
./list_demo
```
