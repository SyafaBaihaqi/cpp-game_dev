#include <iostream>
using namespace std;

int main() {
    int nyawa = 3;
    int skor = 0;
    char aksi;

    cout << "=== Game Skor & Nyawa ===" << endl;

    while (nyawa > 0) {
        cout << "\nAksi (t = tambah skor, k = kena serangan, q = keluar): ";
        cin >> aksi;

        if (aksi == 't') {
            skor += 10;
            cout << "Skor bertambah! Skor sekarang: " << skor << endl;
        } else if (aksi == 'k') {
            nyawa--;
            cout << "Kamu kena serangan! Nyawa tersisa: " << nyawa << endl;
        } else if (aksi == 'q') {
            cout << "Keluar dari permainan." << endl;
            break;
        } else {
            cout << "Aksi tidak dikenal." << endl;
        }
    }

    cout << "\nGame berakhir. Skor akhir: " << skor << endl;

    return 0;
}
