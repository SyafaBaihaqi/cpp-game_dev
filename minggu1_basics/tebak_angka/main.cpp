#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

int main() {
    srand(time(0));  
    int number = rand() % 100 + 1; // angka 1-100
    int guess;
    int attempts = 0;

    cout << "=== Game Tebak Angka ===" << endl;
    cout << "Aku sudah memilih angka antara 1 - 100." << endl;

    do {
        cout << "Tebakanmu: ";
        cin >> guess;
        attempts++;

        if (guess > number) {
            cout << "Terlalu besar!" << endl;
        } else if (guess < number) {
            cout << "Terlalu kecil!" << endl;
        } else {
            cout << "Benar! Angkanya adalah " << number << endl;
            cout << "Kamu menebak dalam " << attempts << " kali percobaan." << endl;
        }
    } while (guess != number);

    return 0;
}
