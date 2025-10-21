#include <iostream>
#include <string>
using namespace std;

// ========================================
// 例1: 基本的なクラス定義
// ========================================
class Rectangle {
public:
    double width;
    double height;

    // メンバ関数：面積を計算
    double getArea() {
        return width * height;
    }

    // メンバ関数：周囲の長さを計算
    double getPerimeter() {
        return 2 * (width + height);
    }
};

// ========================================
// 例2: アクセス指定子の使用
// ========================================
class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // セッター（値を設定）
    void setAccountNumber(string accNum) {
        accountNumber = accNum;
    }

    void setBalance(double bal) {
        if (bal >= 0) {
            balance = bal;
        } else {
            cout << "残高は0以上である必要があります" << endl;
        }
    }

    // ゲッター（値を取得）
    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    // 入金
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << "円を入金しました" << endl;
        }
    }

    // 出金
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << "円を出金しました" << endl;
        } else {
            cout << "出金できません（残高不足または無効な金額）" << endl;
        }
    }
};

// ========================================
// 例3: 複雑なクラス（学生管理）
// ========================================
class Student {
private:
    string name;
    int studentId;
    double gpa;  // Grade Point Average（成績平均）

public:
    // 学生情報を設定
    void setInfo(string n, int id, double g) {
        name = n;
        studentId = id;

        if (g >= 0.0 && g <= 4.0) {
            gpa = g;
        } else {
            cout << "GPAは0.0から4.0の範囲である必要があります" << endl;
            gpa = 0.0;
        }
    }

    // 学生情報を表示
    void displayInfo() {
        cout << "========================================" << endl;
        cout << "学生ID: " << studentId << endl;
        cout << "名前: " << name << endl;
        cout << "GPA: " << gpa << endl;
        cout << "========================================" << endl;
    }

    // 成績の評価を返す
    string getGrade() {
        if (gpa >= 3.5) return "優秀";
        else if (gpa >= 3.0) return "良";
        else if (gpa >= 2.0) return "可";
        else return "要改善";
    }
};

// ========================================
// 例4: 図形クラス（円）
// ========================================
class Circle {
private:
    double radius;
    const double PI = 3.14159265359;

public:
    void setRadius(double r) {
        if (r > 0) {
            radius = r;
        } else {
            cout << "半径は正の値である必要があります" << endl;
            radius = 1.0;
        }
    }

    double getRadius() {
        return radius;
    }

    double getArea() {
        return PI * radius * radius;
    }

    double getCircumference() {
        return 2 * PI * radius;
    }
};

// ========================================
// メイン関数
// ========================================
int main() {
    cout << "=== Lesson 11: クラスとオブジェクト基礎 ===" << endl << endl;

    // 例1: Rectangle クラスの使用
    cout << "【例1】基本的なクラス" << endl;
    Rectangle rect;
    rect.width = 10.0;
    rect.height = 5.0;
    cout << "幅: " << rect.width << ", 高さ: " << rect.height << endl;
    cout << "面積: " << rect.getArea() << endl;
    cout << "周囲の長さ: " << rect.getPerimeter() << endl;
    cout << endl;

    // 例2: BankAccount クラスの使用
    cout << "【例2】アクセス指定子とカプセル化" << endl;
    BankAccount account;
    account.setAccountNumber("123-456-789");
    account.setBalance(10000);

    cout << "口座番号: " << account.getAccountNumber() << endl;
    cout << "初期残高: " << account.getBalance() << "円" << endl;

    account.deposit(5000);
    cout << "現在残高: " << account.getBalance() << "円" << endl;

    account.withdraw(3000);
    cout << "現在残高: " << account.getBalance() << "円" << endl;

    account.withdraw(20000);  // 残高不足
    cout << endl;

    // 例3: Student クラスの使用
    cout << "【例3】学生管理システム" << endl;
    Student student1, student2;

    student1.setInfo("山田太郎", 1001, 3.7);
    student2.setInfo("鈴木花子", 1002, 3.2);

    student1.displayInfo();
    cout << "評価: " << student1.getGrade() << endl << endl;

    student2.displayInfo();
    cout << "評価: " << student2.getGrade() << endl << endl;

    // 例4: Circle クラスの使用
    cout << "【例4】円クラス" << endl;
    Circle circle;
    circle.setRadius(5.0);

    cout << "半径: " << circle.getRadius() << endl;
    cout << "面積: " << circle.getArea() << endl;
    cout << "円周: " << circle.getCircumference() << endl;
    cout << endl;

    // 複数のオブジェクト
    cout << "【応用】複数のオブジェクト操作" << endl;
    Circle circles[3];
    circles[0].setRadius(1.0);
    circles[1].setRadius(2.0);
    circles[2].setRadius(3.0);

    for (int i = 0; i < 3; i++) {
        cout << "円" << (i+1) << " - 半径: " << circles[i].getRadius()
             << ", 面積: " << circles[i].getArea() << endl;
    }

    return 0;
}
