# Lesson 27: 単体テストの書き方

## 学習目標
- 単体テストの重要性を理解する
- Google Test または Catch2 の使い方を学ぶ
- CMake CTest の使い方を理解する
- テスト駆動開発（TDD）の基礎を学ぶ

## 簡易テストフレームワーク

```cpp
#define ASSERT_EQ(a, b) \
    if ((a) != (b)) { \
        cout << "FAILED: " << #a << " != " << #b << endl; \
    } else { \
        cout << "PASSED" << endl; \
    }

void test_add() {
    Calculator calc;
    ASSERT_EQ(calc.add(2, 3), 5);
}
```

## CTest の使用

CMakeLists.txt に追加：
```cmake
enable_testing()
add_test(NAME MyTest COMMAND my_test_exe)
```

実行：
```bash
ctest
```
