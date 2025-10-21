#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ========================================
// 演習1: 日付クラス
// ========================================
// TODO: 以下の要件を満たす Date クラスを実装してください
// - private メンバ変数: year (int), month (int), day (int)
// - デフォルトコンストラクタ: 2024年1月1日で初期化
// - パラメータ付きコンストラクタ: 指定された日付で初期化
// - display(): 日付を "YYYY年MM月DD日" の形式で表示

class Date {
private:
    // ここにメンバ変数を追加

public:
    // ここにコンストラクタとメンバ関数を追加

};

// ========================================
// 演習2: 文字列クラス（簡易版）
// ========================================
// TODO: 以下の要件を満たす MyString クラスを実装してください
// - private メンバ変数: char* str, int length
// - コンストラクタ: 文字列を受け取り、動的メモリを確保してコピー
// - デストラクタ: 確保したメモリを解放
// - コピーコンストラクタ: 深いコピーを行う
// - display(): 文字列と長さを表示
// - getLength(): 文字列の長さを返す

class MyString {
private:
    // ここにメンバ変数を追加

public:
    // ここにコンストラクタ、デストラクタ、メンバ関数を追加

};

// ========================================
// 演習3: カウンタクラス
// ========================================
// TODO: 以下の要件を満たす Counter クラスを実装してください
// - private メンバ変数: int count, static int totalObjects
// - コンストラクタ: count を 0 に初期化、totalObjects をインクリメント
// - パラメータ付きコンストラクタ: count を指定値で初期化
// - デストラクタ: totalObjects をデクリメント
// - increment(): count をインクリメント
// - getCount(): count を返す
// - static getTotalObjects(): totalObjects を返す

class Counter {
private:
    // ここにメンバ変数を追加（static メンバも忘れずに）

public:
    // ここにコンストラクタ、デストラクタ、メンバ関数を追加

};

// 静的メンバ変数の定義をここに追加
// int Counter::totalObjects = 0;

// ========================================
// 演習4: 銀行口座クラス（改良版）
// ========================================
// TODO: 以下の要件を満たす BankAccount クラスを実装してください
// - private メンバ変数: string accountNumber, string ownerName, double balance
// - パラメータ付きコンストラクタ: 口座番号と所有者名を受け取り、残高を0で初期化
// - パラメータ付きコンストラクタ: 口座番号、所有者名、初期残高を受け取る
// - deposit(double amount): 入金
// - withdraw(double amount): 出金
// - display(): 口座情報を表示
// - getBalance(): 残高を返す

class BankAccount {
private:
    // ここにメンバ変数を追加

public:
    // ここにコンストラクタとメンバ関数を追加

};

// ========================================
// 演習5: 配列クラス（チャレンジ問題）
// ========================================
// TODO: 以下の要件を満たす IntArray クラスを実装してください
// - private メンバ変数: int* data, int size
// - コンストラクタ: サイズを受け取り、配列を確保し、全要素を0で初期化
// - デストラクタ: 配列を解放
// - コピーコンストラクタ: 深いコピーを行う
// - set(int index, int value): 指定位置に値を設定
// - get(int index): 指定位置の値を取得
// - display(): 配列の内容を表示
// - getSize(): 配列のサイズを返す

class IntArray {
private:
    // ここにメンバ変数を追加

public:
    // ここにコンストラクタ、デストラクタ、メンバ関数を追加

};

// ========================================
// テスト関数
// ========================================
void testDate() {
    cout << "=== 演習1: 日付クラスのテスト ===" << endl;

    // TODO: Date クラスを使用してテストコードを書いてください
    // 例：
    // Date d1;
    // Date d2(2024, 12, 25);
    // d1.display();
    // d2.display();

    cout << endl;
}

void testMyString() {
    cout << "=== 演習2: 文字列クラスのテスト ===" << endl;

    // TODO: MyString クラスを使用してテストコードを書いてください
    // 例：
    // MyString s1("Hello");
    // MyString s2(s1);  // コピーコンストラクタ
    // s1.display();
    // s2.display();

    cout << endl;
}

void testCounter() {
    cout << "=== 演習3: カウンタクラスのテスト ===" << endl;

    // TODO: Counter クラスを使用してテストコードを書いてください
    // 例：
    // Counter c1;
    // Counter c2(10);
    // cout << "総オブジェクト数: " << Counter::getTotalObjects() << endl;

    cout << endl;
}

void testBankAccount() {
    cout << "=== 演習4: 銀行口座クラスのテスト ===" << endl;

    // TODO: BankAccount クラスを使用してテストコードを書いてください

    cout << endl;
}

void testIntArray() {
    cout << "=== 演習5: 配列クラスのテスト ===" << endl;

    // TODO: IntArray クラスを使用してテストコードを書いてください

    cout << endl;
}

// ========================================
// メイン関数
// ========================================
int main() {
    cout << "=== Lesson 12: 演習問題 ===" << endl << endl;

    testDate();
    testMyString();
    testCounter();
    testBankAccount();
    testIntArray();

    cout << "すべての演習を完了しました！" << endl;

    return 0;
}

// ========================================
// 解答例（自分で実装した後に確認してください）
// ========================================
/*

// Date クラスの解答例
class Date {
private:
    int year, month, day;

public:
    Date() : year(2024), month(1), day(1) {
        cout << "Date: デフォルトコンストラクタ" << endl;
    }

    Date(int y, int m, int d) : year(y), month(m), day(d) {
        cout << "Date: パラメータ付きコンストラクタ" << endl;
    }

    void display() {
        cout << year << "年" << month << "月" << day << "日" << endl;
    }
};

// MyString クラスの解答例
class MyString {
private:
    char* str;
    int length;

public:
    MyString(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
        cout << "MyString: コンストラクタ（\"" << str << "\"）" << endl;
    }

    ~MyString() {
        cout << "MyString: デストラクタ（\"" << str << "\"）" << endl;
        delete[] str;
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
        cout << "MyString: コピーコンストラクタ（\"" << str << "\"）" << endl;
    }

    void display() {
        cout << "文字列: \"" << str << "\", 長さ: " << length << endl;
    }

    int getLength() {
        return length;
    }
};

// Counter クラスの解答例
class Counter {
private:
    int count;
    static int totalObjects;

public:
    Counter() : count(0) {
        totalObjects++;
        cout << "Counter: デフォルトコンストラクタ（総数: " << totalObjects << "）" << endl;
    }

    Counter(int c) : count(c) {
        totalObjects++;
        cout << "Counter: パラメータ付きコンストラクタ（総数: " << totalObjects << "）" << endl;
    }

    ~Counter() {
        totalObjects--;
        cout << "Counter: デストラクタ（残り: " << totalObjects << "）" << endl;
    }

    void increment() {
        count++;
    }

    int getCount() {
        return count;
    }

    static int getTotalObjects() {
        return totalObjects;
    }
};

int Counter::totalObjects = 0;

// BankAccount クラスの解答例
class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;

public:
    BankAccount(string accNum, string owner)
        : accountNumber(accNum), ownerName(owner), balance(0.0) {
        cout << "BankAccount: " << ownerName << " の口座を作成" << endl;
    }

    BankAccount(string accNum, string owner, double initialBalance)
        : accountNumber(accNum), ownerName(owner), balance(initialBalance) {
        cout << "BankAccount: " << ownerName << " の口座を作成（初期残高: "
             << balance << "円）" << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << "円を入金しました" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << "円を出金しました" << endl;
        } else {
            cout << "出金できません" << endl;
        }
    }

    void display() {
        cout << "口座番号: " << accountNumber << endl;
        cout << "所有者: " << ownerName << endl;
        cout << "残高: " << balance << "円" << endl;
    }

    double getBalance() {
        return balance;
    }
};

// IntArray クラスの解答例
class IntArray {
private:
    int* data;
    int size;

public:
    IntArray(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = 0;
        }
        cout << "IntArray: サイズ " << size << " の配列を作成" << endl;
    }

    ~IntArray() {
        delete[] data;
        cout << "IntArray: 配列を解放" << endl;
    }

    IntArray(const IntArray& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "IntArray: コピーコンストラクタ" << endl;
    }

    void set(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    int get(int index) {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return 0;
    }

    void display() {
        cout << "配列: [";
        for (int i = 0; i < size; i++) {
            cout << data[i];
            if (i < size - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    int getSize() {
        return size;
    }
};

*/
