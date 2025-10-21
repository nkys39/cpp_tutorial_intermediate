#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ========================================
// 例1: 基本的な継承
// ========================================
class Animal {
protected:
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {
        cout << "Animal コンストラクタ: " << name << endl;
    }

    virtual ~Animal() {
        cout << "Animal デストラクタ: " << name << endl;
    }

    void eat() {
        cout << name << " is eating" << endl;
    }

    void sleep() {
        cout << name << " is sleeping" << endl;
    }

    virtual void makeSound() {
        cout << name << " makes a sound" << endl;
    }

    void displayInfo() {
        cout << "名前: " << name << ", 年齢: " << age << "歳" << endl;
    }
};

class Dog : public Animal {
private:
    string breed;

public:
    Dog(string n, int a, string b) : Animal(n, a), breed(b) {
        cout << "Dog コンストラクタ: " << name << " (" << breed << ")" << endl;
    }

    ~Dog() {
        cout << "Dog デストラクタ: " << name << endl;
    }

    // オーバーライド
    void makeSound() override {
        cout << name << " says: ワンワン！" << endl;
    }

    void fetch() {
        cout << name << " is fetching the ball" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {
        cout << "Cat コンストラクタ: " << name << endl;
    }

    ~Cat() {
        cout << "Cat デストラクタ: " << name << endl;
    }

    void makeSound() override {
        cout << name << " says: ニャー！" << endl;
    }

    void climb() {
        cout << name << " is climbing a tree" << endl;
    }
};

// ========================================
// 例2: 抽象クラスとポリモーフィズム
// ========================================
class Shape {
protected:
    string color;

public:
    Shape(string c) : color(c) {}
    virtual ~Shape() {}

    // 純粋仮想関数
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void draw() const = 0;

    string getColor() const {
        return color;
    }
};

class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159265359;

public:
    Circle(string c, double r) : Shape(c), radius(r) {}

    double getArea() const override {
        return PI * radius * radius;
    }

    double getPerimeter() const override {
        return 2 * PI * radius;
    }

    void draw() const override {
        cout << "Drawing a " << color << " circle (radius: " << radius << ")" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerimeter() const override {
        return 2 * (width + height);
    }

    void draw() const override {
        cout << "Drawing a " << color << " rectangle (" << width << " x " << height << ")" << endl;
    }
};

class Triangle : public Shape {
private:
    double base, height, side1, side2;

public:
    Triangle(string c, double b, double h, double s1, double s2)
        : Shape(c), base(b), height(h), side1(s1), side2(s2) {}

    double getArea() const override {
        return 0.5 * base * height;
    }

    double getPerimeter() const override {
        return base + side1 + side2;
    }

    void draw() const override {
        cout << "Drawing a " << color << " triangle (base: " << base << ")" << endl;
    }
};

// ========================================
// 例3: 従業員管理システム
// ========================================
class Employee {
protected:
    string name;
    int employeeId;
    double baseSalary;

public:
    Employee(string n, int id, double salary)
        : name(n), employeeId(id), baseSalary(salary) {}

    virtual ~Employee() {}

    // 純粋仮想関数：給与計算
    virtual double calculateSalary() const = 0;

    virtual void displayInfo() const {
        cout << "ID: " << employeeId << ", 名前: " << name;
    }

    string getName() const { return name; }
};

class Manager : public Employee {
private:
    double bonus;
    int teamSize;

public:
    Manager(string n, int id, double salary, double b, int ts)
        : Employee(n, id, salary), bonus(b), teamSize(ts) {}

    double calculateSalary() const override {
        return baseSalary + bonus;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", 役職: マネージャー, チームサイズ: " << teamSize
             << ", 給与: " << calculateSalary() << "万円" << endl;
    }
};

class Engineer : public Employee {
private:
    string specialization;
    int projectCount;

public:
    Engineer(string n, int id, double salary, string spec, int pc)
        : Employee(n, id, salary), specialization(spec), projectCount(pc) {}

    double calculateSalary() const override {
        // プロジェクト数に応じたボーナス
        return baseSalary + (projectCount * 2);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", 役職: エンジニア, 専門: " << specialization
             << ", プロジェクト数: " << projectCount
             << ", 給与: " << calculateSalary() << "万円" << endl;
    }
};

// ========================================
// 例4: 多重継承
// ========================================
class Flyable {
public:
    virtual void fly() {
        cout << "Flying in the air" << endl;
    }
};

class Swimmable {
public:
    virtual void swim() {
        cout << "Swimming in the water" << endl;
    }
};

class Duck : public Animal, public Flyable, public Swimmable {
public:
    Duck(string n, int a) : Animal(n, a) {}

    void makeSound() override {
        cout << name << " says: クワックワッ！" << endl;
    }

    void fly() override {
        cout << name << " is flying" << endl;
    }

    void swim() override {
        cout << name << " is swimming" << endl;
    }
};

// ========================================
// 例5: 仮想デストラクタの重要性
// ========================================
class Base {
public:
    Base() {
        cout << "Base コンストラクタ" << endl;
    }

    virtual ~Base() {
        cout << "Base デストラクタ" << endl;
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[10];
        cout << "Derived コンストラクタ（メモリ確保）" << endl;
    }

    ~Derived() {
        delete[] data;
        cout << "Derived デストラクタ（メモリ解放）" << endl;
    }
};

// ========================================
// メイン関数
// ========================================
int main() {
    cout << "=== Lesson 13: 継承とポリモーフィズム ===" << endl << endl;

    // 例1: 基本的な継承
    cout << "【例1】基本的な継承" << endl;
    Dog dog("ポチ", 3, "柴犬");
    dog.displayInfo();
    dog.eat();
    dog.makeSound();
    dog.fetch();
    cout << endl;

    Cat cat("タマ", 2);
    cat.displayInfo();
    cat.makeSound();
    cat.climb();
    cout << endl;

    // ポリモーフィズムのデモ
    cout << "【ポリモーフィズム】" << endl;
    Animal* animals[2];
    animals[0] = new Dog("ハチ", 5, "秋田犬");
    animals[1] = new Cat("ミケ", 3);

    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 2; i++) {
        delete animals[i];  // 仮想デストラクタのおかげで正しく解放される
    }
    cout << endl;

    // 例2: 抽象クラス
    cout << "【例2】図形クラス（抽象クラス）" << endl;
    vector<Shape*> shapes;
    shapes.push_back(new Circle("赤", 5.0));
    shapes.push_back(new Rectangle("青", 4.0, 6.0));
    shapes.push_back(new Triangle("緑", 3.0, 4.0, 3.0, 5.0));

    for (Shape* shape : shapes) {
        shape->draw();
        cout << "  面積: " << shape->getArea() << endl;
        cout << "  周囲の長さ: " << shape->getPerimeter() << endl;
    }

    for (Shape* shape : shapes) {
        delete shape;
    }
    cout << endl;

    // 例3: 従業員管理システム
    cout << "【例3】従業員管理システム" << endl;
    vector<Employee*> employees;
    employees.push_back(new Manager("山田太郎", 1001, 50, 20, 5));
    employees.push_back(new Engineer("鈴木花子", 1002, 40, "AI", 3));
    employees.push_back(new Engineer("田中一郎", 1003, 45, "Web", 5));

    double totalSalary = 0;
    for (Employee* emp : employees) {
        emp->displayInfo();
        totalSalary += emp->calculateSalary();
    }
    cout << "総給与: " << totalSalary << "万円" << endl;

    for (Employee* emp : employees) {
        delete emp;
    }
    cout << endl;

    // 例4: 多重継承
    cout << "【例4】多重継承" << endl;
    Duck duck("ドナルド", 2);
    duck.makeSound();
    duck.fly();
    duck.swim();
    cout << endl;

    // 例5: 仮想デストラクタの重要性
    cout << "【例5】仮想デストラクタ" << endl;
    {
        Base* obj = new Derived();
        delete obj;  // 仮想デストラクタのおかげで Derived のデストラクタも呼ばれる
    }

    return 0;
}
