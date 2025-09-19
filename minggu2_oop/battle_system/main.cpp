#include <iostream>
#include <vector>
using namespace std;

class Character {
public:
    string nama;
    int hp;
    int attack;

    Character(string n, int h, int a) : nama(n), hp(h), attack(a) {}

    virtual void serang(Character &target) {
        cout << nama << " menyerang " << target.nama << " dengan damage " << attack << endl;
        target.hp -= attack;
    }

    bool isAlive() {
        return hp > 0;
    }
};

class Player : public Character {
public:
    Player(string n, int h, int a) : Character(n, h, a) {}
};

class Enemy : public Character {
public:
    Enemy(string n, int h, int a) : Character(n, h, a) {}
};

class BossEnemy : public Enemy {
public:
    int specialAttack;
    BossEnemy(string n, int h, int a, int s) : Enemy(n, h, a), specialAttack(s) {}

    void serang(Character &target) override {
        cout << nama << " melancarkan serangan BOSSS!!! Damage: " << specialAttack << endl;
        target.hp -= specialAttack;
    }
};

int main() {
    Player p1("Syafa", 100, 15);
    Enemy goblin("Goblin", 50, 10);
    BossEnemy naga("Naga Hitam", 200, 20, 40);

    cout << "=== Battle Dimulai ===\n";

    p1.serang(goblin);
    goblin.serang(p1);
    naga.serang(p1);

    cout << p1.nama << " HP: " << p1.hp << endl;
    cout << goblin.nama << " HP: " << goblin.hp << endl;
    cout << naga.nama << " HP: " << naga.hp << endl;

    return 0;
}
