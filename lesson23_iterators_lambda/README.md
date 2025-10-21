# Lesson 23: イテレータとラムダ式

## 学習目標
- イテレータの種類と使い方を学ぶ
- ラムダ式の構文と活用方法を理解する
- 関数オブジェクトの概念を学ぶ

## イテレータの種類

1. **Input Iterator**: 読み取り専用
2. **Output Iterator**: 書き込み専用
3. **Forward Iterator**: 前進のみ
4. **Bidirectional Iterator**: 双方向
5. **Random Access Iterator**: ランダムアクセス

## ラムダ式

```cpp
auto add = [](int a, int b) { return a + b; };
int result = add(3, 4);  // 7

// キャプチャ
int x = 10;
auto addX = [x](int a) { return a + x; };
auto addXRef = [&x](int a) { return a + x; };
```
