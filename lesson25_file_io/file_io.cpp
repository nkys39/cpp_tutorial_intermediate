#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "=== Lesson 25: ファイル入出力 ===" << endl << endl;

    // ファイルへの書き込み
    cout << "【ファイル書き込み】" << endl;
    ofstream ofs("test.txt");
    if (ofs.is_open()) {
        ofs << "Hello, World!" << endl;
        ofs << "C++ File I/O" << endl;
        ofs << "Line 3" << endl;
        ofs.close();
        cout << "test.txt に書き込みました" << endl;
    }
    cout << endl;

    // ファイルからの読み込み
    cout << "【ファイル読み込み】" << endl;
    ifstream ifs("test.txt");
    if (ifs.is_open()) {
        string line;
        while (getline(ifs, line)) {
            cout << line << endl;
        }
        ifs.close();
    }
    cout << endl;

    // 追記モード
    cout << "【追記モード】" << endl;
    ofstream ofs_append("test.txt", ios::app);
    if (ofs_append.is_open()) {
        ofs_append << "追加された行" << endl;
        ofs_append.close();
        cout << "test.txt に追記しました" << endl;
    }
    cout << endl;

    // バイナリファイル
    cout << "【バイナリファイル】" << endl;
    ofstream ofs_bin("data.bin", ios::binary);
    if (ofs_bin.is_open()) {
        int numbers[] = {10, 20, 30, 40, 50};
        ofs_bin.write(reinterpret_cast<char*>(numbers), sizeof(numbers));
        ofs_bin.close();
        cout << "data.bin にバイナリデータを書き込みました" << endl;
    }

    ifstream ifs_bin("data.bin", ios::binary);
    if (ifs_bin.is_open()) {
        int numbers[5];
        ifs_bin.read(reinterpret_cast<char*>(numbers), sizeof(numbers));
        ifs_bin.close();

        cout << "読み込んだデータ: ";
        for (int n : numbers) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}
