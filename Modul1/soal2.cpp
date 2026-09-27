#include <iostream>
using namespace std;

string satuan(int angka) {
    switch (angka) {
        case 1: return "satu";
        case 2: return "dua";
        case 3: return "tiga";
        case 4: return "empat";
        case 5: return "lima";
        case 6: return "enam";
        case 7: return "tujuh";
        case 8: return "delapan";
        case 9: return "sembilan";
        default: return "";
    }
}

int main() {
    int angka;

    cout << "Masukkan angka: ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka di luar jangkauan";
    } else if (angka == 0) {
        cout << "nol";
    } else if (angka == 100) {
        cout << "seratus";
    } else if (angka < 10) {
        cout << satuan(angka);
    } else if (angka == 10) {
        cout << "sepuluh";
    } else if (angka == 11) {
        cout << "sebelas";
    } else if (angka < 20) {
        cout << satuan(angka - 10) << " belas";
    } else {
        int puluhan = angka / 10;
        int sisa = angka % 10;

        cout << satuan(puluhan) << " puluh";

        if (sisa != 0)
            cout << " " << satuan(sisa);
    }
    return 0;
}