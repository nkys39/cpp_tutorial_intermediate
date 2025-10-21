# Lesson 20: map と multimap

## 学習目標
- map（連想配列）の使い方を学ぶ
- multimap の使い方を学ぶ
- キーと値のペアを扱う方法を理解する

## map

キーと値のペアを格納：

```cpp
#include <map>

map<string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;

cout << ages["Alice"] << endl;  // 25

for (auto& pair : ages) {
    cout << pair.first << ": " << pair.second << endl;
}
```

## multimap

同じキーで複数の値を格納可能：

```cpp
multimap<string, int> scores;
scores.insert({"Alice", 85});
scores.insert({"Alice", 92});
```
