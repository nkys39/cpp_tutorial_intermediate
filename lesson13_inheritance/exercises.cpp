#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ========================================
// 演習1: 従業員管理システム
// ========================================
// TODO: 以下のクラス階層を実装してください

// 基底クラス Employee
// - private メンバ: name (string), employeeId (int), baseSalary (double)
// - public メソッド:
//   - コンストラクタ
//   - virtual double calculateSalary() const = 0  (純粋仮想関数)
//   - virtual void displayInfo() const

class Employee {
    // ここに実装
};

// 派生クラス Manager
// - private メンバ: bonus (double), department (string)
// - public メソッド:
//   - コンストラクタ
//   - calculateSalary() のオーバーライド（基本給 + ボーナス）
//   - displayInfo() のオーバーライド

class Manager : public Employee {
    // ここに実装
};

// 派生クラス Engineer
// - private メンバ: specialization (string), projectCount (int)
// - public メソッド:
//   - コンストラクタ
//   - calculateSalary() のオーバーライド（基本給 + プロジェクト数 × 2万円）
//   - displayInfo() のオーバーライド

class Engineer : public Employee {
    // ここに実装
};

// 派生クラス Intern
// - private メンバ: school (string), hoursPerWeek (int)
// - public メソッド:
//   - コンストラクタ
//   - calculateSalary() のオーバーライド（時給 × 週の時間数 × 4週）
//   - displayInfo() のオーバーライド

class Intern : public Employee {
    // ここに実装
};

// ========================================
// 演習2: 図形クラス階層
// ========================================
// TODO: 以下のクラス階層を実装してください

// 抽象クラス Shape
// - protected メンバ: color (string)
// - public メソッド:
//   - コンストラクタ
//   - virtual double getArea() const = 0
//   - virtual double getPerimeter() const = 0
//   - virtual void draw() const = 0
//   - getColor() const

class Shape {
    // ここに実装
};

// 派生クラス Circle
// - private メンバ: radius (double)
// - すべての純粋仮想関数を実装

class Circle : public Shape {
    // ここに実装
};

// 派生クラス Rectangle
// - private メンバ: width (double), height (double)
// - すべての純粋仮想関数を実装

class Rectangle : public Shape {
    // ここに実装
};

// 派生クラス Triangle
// - private メンバ: side1, side2, side3 (double)
// - すべての純粋仮想関数を実装
// - ヘロンの公式を使用して面積を計算

class Triangle : public Shape {
    // ここに実装
};

// ========================================
// 演習3: 動物クラス
// ========================================
// TODO: 以下のクラス階層を実装してください

// 基底クラス Animal
// - protected メンバ: name (string), age (int), weight (double)
// - public メソッド:
//   - コンストラクタ
//   - virtual ~Animal()
//   - virtual void makeSound() const = 0
//   - virtual void move() const = 0
//   - displayInfo() const

class Animal {
    // ここに実装
};

// 派生クラス Dog
// - private メンバ: breed (string)
// - makeSound(), move() のオーバーライド

class Dog : public Animal {
    // ここに実装
};

// 派生クラス Cat
// - private メンバ: indoorOnly (bool)
// - makeSound(), move() のオーバーライド

class Cat : public Animal {
    // ここに実装
};

// 派生クラス Bird
// - private メンバ: canFly (bool), wingSpan (double)
// - makeSound(), move() のオーバーライド

class Bird : public Animal {
    // ここに実装
};

// ========================================
// 演習4: 乗り物クラス（チャレンジ問題）
// ========================================
// TODO: 以下のクラス階層を実装してください

// 抽象クラス Vehicle
// - protected メンバ: model (string), year (int), price (double)
// - public メソッド:
//   - virtual double calculateTax() const = 0
//   - virtual void displayInfo() const

class Vehicle {
    // ここに実装
};

// 派生クラス Car
// - private メンバ: numDoors (int), engineSize (double)
// - calculateTax(): price の 5% + エンジンサイズ × 0.5万円

class Car : public Vehicle {
    // ここに実装
};

// 派生クラス Motorcycle
// - private メンバ: engineCC (int)
// - calculateTax(): price の 3%

class Motorcycle : public Vehicle {
    // ここに実装
};

// 派生クラス Bicycle
// - private メンバ: gearCount (int)
// - calculateTax(): 0（税金なし）

class Bicycle : public Vehicle {
    // ここに実装
};

// ========================================
// テスト関数
// ========================================
void testEmployee() {
    cout << "=== 演習1: 従業員管理システムのテスト ===" << endl;

    // TODO: Employee, Manager, Engineer, Intern を使用してテスト
    // 例：
    // vector<Employee*> employees;
    // employees.push_back(new Manager(...));
    // employees.push_back(new Engineer(...));
    // ...

    cout << endl;
}

void testShape() {
    cout << "=== 演習2: 図形クラスのテスト ===" << endl;

    // TODO: Shape, Circle, Rectangle, Triangle を使用してテスト

    cout << endl;
}

void testAnimal() {
    cout << "=== 演習3: 動物クラスのテスト ===" << endl;

    // TODO: Animal, Dog, Cat, Bird を使用してテスト

    cout << endl;
}

void testVehicle() {
    cout << "=== 演習4: 乗り物クラスのテスト ===" << endl;

    // TODO: Vehicle, Car, Motorcycle, Bicycle を使用してテスト

    cout << endl;
}

// ========================================
// メイン関数
// ========================================
int main() {
    cout << "=== Lesson 13: 演習問題 ===" << endl << endl;

    testEmployee();
    testShape();
    testAnimal();
    testVehicle();

    cout << "すべての演習を完了しました！" << endl;

    return 0;
}

// ========================================
// 解答例（自分で実装した後に確認してください）
// ========================================
/*

// Employee クラスの解答例
class Employee {
protected:
    string name;
    int employeeId;
    double baseSalary;

public:
    Employee(string n, int id, double salary)
        : name(n), employeeId(id), baseSalary(salary) {}

    virtual ~Employee() {}

    virtual double calculateSalary() const = 0;

    virtual void displayInfo() const {
        cout << "ID: " << employeeId << ", 名前: " << name
             << ", 給与: " << calculateSalary() << "万円" << endl;
    }
};

class Manager : public Employee {
private:
    double bonus;
    string department;

public:
    Manager(string n, int id, double salary, double b, string dept)
        : Employee(n, id, salary), bonus(b), department(dept) {}

    double calculateSalary() const override {
        return baseSalary + bonus;
    }

    void displayInfo() const override {
        cout << "【マネージャー】";
        Employee::displayInfo();
        cout << "  部署: " << department << endl;
    }
};

// 他のクラスも同様に実装...

*/
