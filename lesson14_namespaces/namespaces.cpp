#include <iostream>
#include <string>
using namespace std;

// ========================================
// 例1: 基本的な名前空間
// ========================================
namespace Math {
    const double PI = 3.14159265359;
    const double E = 2.71828182846;

    double add(double a, double b) {
        return a + b;
    }

    double subtract(double a, double b) {
        return a - b;
    }

    class Calculator {
    public:
        static double multiply(double a, double b) {
            return a * b;
        }

        static double divide(double a, double b) {
            if (b != 0) return a / b;
            return 0;
        }
    };
}

// ========================================
// 例2: ネストした名前空間
// ========================================
namespace Company {
    namespace HR {
        class Employee {
        private:
            string name;
            int id;

        public:
            Employee(string n, int i) : name(n), id(i) {}

            void display() {
                cout << "HR従業員: " << name << " (ID: " << id << ")" << endl;
            }
        };
    }

    namespace IT {
        class Employee {
        private:
            string name;
            int id;
            string role;

        public:
            Employee(string n, int i, string r) : name(n), id(i), role(r) {}

            void display() {
                cout << "IT従業員: " << name << " (ID: " << id << ", " << role << ")" << endl;
            }
        };
    }
}

// ========================================
// 例3: 列挙型（従来の enum）
// ========================================
enum Color {
    RED = 0,
    GREEN = 1,
    BLUE = 2
};

enum Size {
    SMALL,
    MEDIUM,
    LARGE,
    XLARGE
};

// ========================================
// 例4: enum class
// ========================================
enum class TrafficLight {
    Red,
    Yellow,
    Green
};

enum class GameState {
    Menu,
    Playing,
    Paused,
    GameOver
};

enum class Direction : uint8_t {
    North = 0,
    East = 1,
    South = 2,
    West = 3
};

// ========================================
// 例5: enum class を使った状態管理
// ========================================
class GameManager {
private:
    GameState state;
    int score;

public:
    GameManager() : state(GameState::Menu), score(0) {}

    void setState(GameState newState) {
        state = newState;

        switch (state) {
            case GameState::Menu:
                cout << "メニュー画面" << endl;
                break;
            case GameState::Playing:
                cout << "ゲーム中" << endl;
                break;
            case GameState::Paused:
                cout << "一時停止" << endl;
                break;
            case GameState::GameOver:
                cout << "ゲームオーバー（スコア: " << score << "）" << endl;
                break;
        }
    }

    void addScore(int points) {
        if (state == GameState::Playing) {
            score += points;
            cout << "スコア +=" << points << " (合計: " << score << ")" << endl;
        }
    }

    GameState getState() const {
        return state;
    }
};

// ========================================
// 例6: 匿名名前空間
// ========================================
namespace {
    int internalCounter = 0;

    void internalFunction() {
        internalCounter++;
        cout << "内部関数が呼ばれました（" << internalCounter << "回目）" << endl;
    }
}

// ========================================
// メイン関数
// ========================================
int main() {
    cout << "=== Lesson 14: 名前空間と列挙型 ===" << endl << endl;

    // 例1: 基本的な名前空間
    cout << "【例1】名前空間の使用" << endl;
    cout << "PI = " << Math::PI << endl;
    cout << "5 + 3 = " << Math::add(5, 3) << endl;
    cout << "10 * 2 = " << Math::Calculator::multiply(10, 2) << endl;
    cout << endl;

    // using 宣言
    {
        using namespace Math;
        cout << "using namespace Math:" << endl;
        cout << "E = " << E << endl;
        cout << "8 - 3 = " << subtract(8, 3) << endl;
    }
    cout << endl;

    // 例2: ネストした名前空間
    cout << "【例2】ネストした名前空間" << endl;
    Company::HR::Employee hrEmp("山田太郎", 1001);
    Company::IT::Employee itEmp("鈴木花子", 2001, "エンジニア");
    hrEmp.display();
    itEmp.display();
    cout << endl;

    // 例3: 従来の enum
    cout << "【例3】従来の enum" << endl;
    Color favoriteColor = RED;
    Size shirtSize = MEDIUM;

    cout << "色: " << favoriteColor << endl;
    cout << "サイズ: " << shirtSize << endl;

    // 問題点：暗黙の型変換
    int colorValue = RED;  // これができてしまう
    cout << "色の値（int）: " << colorValue << endl;
    cout << endl;

    // 例4: enum class
    cout << "【例4】enum class" << endl;
    TrafficLight light = TrafficLight::Red;

    switch (light) {
        case TrafficLight::Red:
            cout << "信号: 赤 - 停止" << endl;
            break;
        case TrafficLight::Yellow:
            cout << "信号: 黄 - 注意" << endl;
            break;
        case TrafficLight::Green:
            cout << "信号: 緑 - 進行" << endl;
            break;
    }

    // int x = TrafficLight::Red;  // エラー：暗黙の型変換なし
    int x = static_cast<int>(TrafficLight::Red);  // 明示的な変換が必要
    cout << "信号の値（明示的変換）: " << x << endl;
    cout << endl;

    // 例5: ゲーム状態管理
    cout << "【例5】enum class を使った状態管理" << endl;
    GameManager game;

    game.setState(GameState::Playing);
    game.addScore(100);
    game.addScore(50);

    game.setState(GameState::Paused);
    game.addScore(25);  // 一時停止中なので加算されない

    game.setState(GameState::Playing);
    game.addScore(75);

    game.setState(GameState::GameOver);
    cout << endl;

    // 例6: Direction（基底型指定）
    cout << "【例6】基底型を指定した enum class" << endl;
    Direction dir = Direction::North;
    cout << "方向のサイズ: " << sizeof(dir) << " バイト" << endl;
    cout << "方向の値: " << static_cast<int>(dir) << endl;

    // 方向を変更
    for (int i = 0; i < 4; i++) {
        dir = static_cast<Direction>(i);
        cout << "方向 " << i << ": ";

        switch (dir) {
            case Direction::North: cout << "北" << endl; break;
            case Direction::East:  cout << "東" << endl; break;
            case Direction::South: cout << "南" << endl; break;
            case Direction::West:  cout << "西" << endl; break;
        }
    }
    cout << endl;

    // 例7: 匿名名前空間
    cout << "【例7】匿名名前空間" << endl;
    internalFunction();
    internalFunction();
    internalFunction();

    return 0;
}
