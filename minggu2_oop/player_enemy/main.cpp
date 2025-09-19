#include <iostream>
using namespace std;

class Player {
public:
    string nama;
    int hp;
    int attack;

    Player(string n, int h, int a) {
        nama = n;
        hp = h;
        attack = a;
    }

    void serang(class Enemy &musuh);
};

class Enemy {
public:
    string nama;
    int hp;
    int attack;

    Enemy(string n, int h, int a) {
        nama = n;
        hp = h;
        attack = a;
    }

    void serang(Player &pemain) {
        cout << nama << " menyerang " << pemain.nama << " dengan damage " << attack << endl;
        pemain.hp -= attack;
    }
};

void Player::serang(Enemy &musuh) {
    cout << nama << " menyerang " << musuh.nama << " dengan damage " << attack << endl;
    musuh.hp -= attack;
}

int main() {
    Player p1("Syafa", 100, 15);
    Enemy e1("Goblin", 50, 10);

    p1.serang(e1);
    e1.serang(p1);

    cout << p1.nama << " HP: " << p1.hp << endl;
    cout << e1.nama << " HP: " << e1.hp << endl;

    return 0;
}
