#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// TODO: 以下の演習を実装してください

// ========================================
// 演習1: 数学ライブラリの名前空間
// ========================================
// Math 名前空間を作成し、以下を実装してください：
// - 定数: PI, E
// - 関数: square(x), cube(x), sqrt(x), pow(x, y)
// - クラス: Point (x, y座標を持ち、distance メソッドで原点からの距離を計算)

namespace Math {
    // ここに実装
}

// ========================================
// 演習2: ゲームの enum class
// ========================================
// 以下の enum class を作成してください：
// - CharacterClass: Warrior, Mage, Archer, Healer
// - ItemType: Weapon, Armor, Potion, QuestItem
// - Rarity: Common, Uncommon, Rare, Epic, Legendary

// ここに実装

// ========================================
// 演習3: ゲームキャラクター管理
// ========================================
// Game 名前空間を作成し、Character クラスを実装してください：
// - private: name, characterClass, level, health
// - メソッド: attack(), heal(), displayInfo()

namespace Game {
    // ここに実装
}

// ========================================
// テスト関数
// ========================================
void testMath() {
    cout << "=== 演習1: 数学ライブラリのテスト ===" << endl;

    // TODO: Math 名前空間の機能をテスト

    cout << endl;
}

void testEnums() {
    cout << "=== 演習2: enum class のテスト ===" << endl;

    // TODO: 作成した enum class をテスト

    cout << endl;
}

void testGame() {
    cout << "=== 演習3: ゲームキャラクター管理のテスト ===" << endl;

    // TODO: Game::Character をテスト

    cout << endl;
}

int main() {
    cout << "=== Lesson 14: 演習問題 ===" << endl << endl;

    testMath();
    testEnums();
    testGame();

    cout << "すべての演習を完了しました！" << endl;

    return 0;
}
