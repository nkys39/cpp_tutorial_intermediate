# Lesson 18: stack, queue, priority_queue

## 学習目標
- stack（スタック）の使い方を学ぶ
- queue（キュー）の使い方を学ぶ
- priority_queue（優先度付きキュー）の使い方を学ぶ

## stack（LIFO: Last In First Out）

```cpp
#include <stack>

stack<int> st;
st.push(10);
st.push(20);
int top = st.top();  // 20
st.pop();
```

## queue（FIFO: First In First Out）

```cpp
#include <queue>

queue<int> q;
q.push(10);
q.push(20);
int front = q.front();  // 10
q.pop();
```

## priority_queue（優先度付きキュー）

```cpp
#include <queue>

priority_queue<int> pq;
pq.push(30);
pq.push(10);
pq.push(20);
int top = pq.top();  // 30（最大値）
```
