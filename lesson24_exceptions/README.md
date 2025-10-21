# Lesson 24: 例外処理

## 学習目標
- 例外処理の基本（try-catch）を学ぶ
- 例外クラスの定義と使用方法を理解する
- RAII パターンを学ぶ

## 基本構文

```cpp
try {
    // 例外が発生する可能性のあるコード
    throw runtime_error("エラーが発生しました");
} catch (const exception& e) {
    cout << "例外: " << e.what() << endl;
}
```

## カスタム例外

```cpp
class MyException : public exception {
public:
    const char* what() const noexcept override {
        return "独自の例外";
    }
};
```
