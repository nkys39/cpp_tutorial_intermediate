# Lesson 25: ファイル入出力

## 学習目標
- fstream を使ったファイル操作を学ぶ
- テキストファイルの読み書きを理解する
- バイナリファイルの扱い方を学ぶ

## テキストファイルの読み書き

### 書き込み
```cpp
#include <fstream>

ofstream ofs("output.txt");
ofs << "Hello, World!" << endl;
ofs.close();
```

### 読み込み
```cpp
ifstream ifs("input.txt");
string line;
while (getline(ifs, line)) {
    cout << line << endl;
}
ifs.close();
```

## バイナリファイル

```cpp
ofstream ofs("data.bin", ios::binary);
int value = 42;
ofs.write(reinterpret_cast<char*>(&value), sizeof(value));
```
