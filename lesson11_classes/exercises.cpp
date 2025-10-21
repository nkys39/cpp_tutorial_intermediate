#include <iostream>
#include <string>
using namespace std;

// ========================================
// 演習1: 学生クラス
// ========================================
// TODO: 以下の要件を満たす Student クラスを実装してください
// - private メンバ変数: name (string), grade (int), score (double)
// - public メンバ関数:
//   - setInfo(string n, int g, double s): 学生情報を設定
//   - displayInfo(): 学生情報を表示
//   - isPassing(): 成績が60点以上なら true を返す

class Student {
private:
    // ここにメンバ変数を追加

public:
    // ここにメンバ関数を追加

};

// ========================================
// 演習2: 銀行口座クラス
// ========================================
// TODO: 以下の要件を満たす BankAccount クラスを実装してください
// - private メンバ変数: accountNumber (string), balance (double)
// - public メンバ関数:
//   - setAccountNumber(string num): 口座番号を設定
//   - deposit(double amount): 入金（0より大きい金額のみ）
//   - withdraw(double amount): 出金（残高以下の金額のみ）
//   - getBalance(): 残高を返す
//   - displayInfo(): 口座情報を表示

class BankAccount {
private:
    // ここにメンバ変数を追加

public:
    // ここにメンバ関数を追加

};

// ========================================
// 演習3: 図書クラス
// ========================================
// TODO: 以下の要件を満たす Book クラスを実装してください
// - private メンバ変数: title (string), author (string), year (int), price (double)
// - public メンバ関数:
//   - setInfo(string t, string a, int y, double p): 本の情報を設定
//   - displayInfo(): 本の情報を表示
//   - applyDiscount(double percentage): 割引を適用（0-100%）
//   - getPrice(): 価格を返す

class Book {
private:
    // ここにメンバ変数を追加

public:
    // ここにメンバ関数を追加

};

// ========================================
// 演習4: 商品クラス（チャレンジ問題）
// ========================================
// TODO: 以下の要件を満たす Product クラスを実装してください
// - private メンバ変数:
//   - productId (string)
//   - productName (string)
//   - price (double)
//   - stock (int)
// - public メンバ関数:
//   - setInfo(...): 商品情報を設定
//   - displayInfo(): 商品情報を表示
//   - addStock(int amount): 在庫を追加
//   - sell(int quantity): 商品を販売（在庫がある場合のみ）
//   - getStock(): 在庫数を返す
//   - getTotalValue(): 在庫の総額を返す（価格 × 在庫数）

class Product {
private:
    // ここにメンバ変数を追加

public:
    // ここにメンバ関数を追加

};

// ========================================
// テスト関数
// ========================================
void testStudent() {
    cout << "=== 演習1: 学生クラスのテスト ===" << endl;

    // TODO: Student クラスを使用してテストコードを書いてください
    // 例：
    // Student s;
    // s.setInfo("山田太郎", 3, 85.5);
    // s.displayInfo();

    cout << endl;
}

void testBankAccount() {
    cout << "=== 演習2: 銀行口座クラスのテスト ===" << endl;

    // TODO: BankAccount クラスを使用してテストコードを書いてください

    cout << endl;
}

void testBook() {
    cout << "=== 演習3: 図書クラスのテスト ===" << endl;

    // TODO: Book クラスを使用してテストコードを書いてください

    cout << endl;
}

void testProduct() {
    cout << "=== 演習4: 商品クラスのテスト ===" << endl;

    // TODO: Product クラスを使用してテストコードを書いてください

    cout << endl;
}

// ========================================
// メイン関数
// ========================================
int main() {
    cout << "=== Lesson 11: 演習問題 ===" << endl << endl;

    testStudent();
    testBankAccount();
    testBook();
    testProduct();

    cout << "すべての演習を完了しました！" << endl;

    return 0;
}

// ========================================
// 解答例（自分で実装した後に確認してください）
// ========================================
/*

// Student クラスの解答例
class Student {
private:
    string name;
    int grade;
    double score;

public:
    void setInfo(string n, int g, double s) {
        name = n;
        grade = g;
        score = s;
    }

    void displayInfo() {
        cout << "名前: " << name << ", 学年: " << grade
             << "年, 成績: " << score << "点" << endl;
    }

    bool isPassing() {
        return score >= 60.0;
    }
};

// BankAccount クラスの解答例
class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    void setAccountNumber(string num) {
        accountNumber = num;
        balance = 0.0;
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

    double getBalance() {
        return balance;
    }

    void displayInfo() {
        cout << "口座番号: " << accountNumber
             << ", 残高: " << balance << "円" << endl;
    }
};

// Book クラスの解答例
class Book {
private:
    string title;
    string author;
    int year;
    double price;

public:
    void setInfo(string t, string a, int y, double p) {
        title = t;
        author = a;
        year = y;
        price = p;
    }

    void displayInfo() {
        cout << "タイトル: " << title << endl;
        cout << "著者: " << author << endl;
        cout << "出版年: " << year << "年" << endl;
        cout << "価格: " << price << "円" << endl;
    }

    void applyDiscount(double percentage) {
        if (percentage >= 0 && percentage <= 100) {
            price = price * (1.0 - percentage / 100.0);
        }
    }

    double getPrice() {
        return price;
    }
};

// Product クラスの解答例
class Product {
private:
    string productId;
    string productName;
    double price;
    int stock;

public:
    void setInfo(string id, string name, double p, int s) {
        productId = id;
        productName = name;
        price = p;
        stock = s;
    }

    void displayInfo() {
        cout << "商品ID: " << productId << endl;
        cout << "商品名: " << productName << endl;
        cout << "価格: " << price << "円" << endl;
        cout << "在庫: " << stock << "個" << endl;
    }

    void addStock(int amount) {
        if (amount > 0) {
            stock += amount;
            cout << amount << "個を追加しました" << endl;
        }
    }

    void sell(int quantity) {
        if (quantity > 0 && quantity <= stock) {
            stock -= quantity;
            cout << quantity << "個を販売しました" << endl;
        } else {
            cout << "在庫が不足しています" << endl;
        }
    }

    int getStock() {
        return stock;
    }

    double getTotalValue() {
        return price * stock;
    }
};

*/
