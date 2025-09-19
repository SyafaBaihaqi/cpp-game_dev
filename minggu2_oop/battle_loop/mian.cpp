#include <iostream>
#include <cstdlib>
#include <ctime>
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

    void heal() {
        int healAmount = rand() % 15 + 5; // heal acak antara 5-20
        hp += healAmount;
        cout << nama << " memulihkan HP sebanyak " << healAmount << endl;
    }
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
        if (rand() % 2 == 0) {
            cout << nama << " melancarkan serangan BOSSS!!! Damage: " << specialAttack << endl;
            target.hp -= specialAttack;
        } else {
            Enemy::serang(target); // serangan biasa
        }
    }
};

int main() {
    srand(time(0));

    Player p1("Syafa", 100, 15);
    BossEnemy naga("Naga Hitam", 120, 10, 30);

    cout << "=== Pertarungan Dimulai ===" << endl;

    while (p1.isAlive() && naga.isAlive()) {
        cout << "\n--- Status ---" << endl;
        cout << p1.nama << " HP: " << p1.hp << endl;
        cout << naga.nama << " HP: " << naga.hp << endl;

        cout << "\nAksi (1 = Serang, 2 = Heal, 3 = Kabur): ";
        int pilihan;
        cin >> pilihan;

        if (pilihan == 1) {
            p1.serang(naga);
        } else if (pilihan == 2) {
            p1.heal();
        } else if (pilihan == 3) {
            cout << p1.nama << " memilih kabur dari pertempuran!" << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
            continue;
        }

        // giliran boss kalau masih hidup
        if (naga.isAlive()) {
            naga.serang(p1);
        }
    }

    cout << "\n=== Pertarungan Selesai ===" << endl;
    if (p1.isAlive() && naga.isAlive() == false) {
        cout << p1.nama << " menang melawan " << naga.nama << "!" << endl;
    } else if (!p1.isAlive()) {
        cout << p1.nama << " kalah... Game Over!" << endl;
    }

    return 0;
}
