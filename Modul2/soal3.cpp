#include <iostream>
using namespace std;

int maksimum(int arr[], int n) {
    int maks = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maks)
            maks = arr[i];
    }
    return maks;
}

int minimum(int arr[], int n) {
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

void rataRata(int arr[], int n, float &rata) {
    int jumlah = 0;

    for (int i = 0; i < n; i++)
        jumlah += arr[i];

    rata = (float) jumlah / n;
}

int main() {
    int arrA[10] = {48, 2, 7, 21, 5, 20, 77, 9, 10, 1};
    int pilih;
    float rata;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            for (int i = 0; i < 10; i++)
                cout << arrA[i] << " ";
            cout << endl;
        }
        else if (pilih == 2) {
            cout << "Nilai maksimum = "
                 << maksimum(arrA, 10) << endl;
        }
        else if (pilih == 3) {
            cout << "Nilai minimum = "
                 << minimum(arrA, 10) << endl;
        }
        else if (pilih == 4) {
            rataRata(arrA, 10, rata);
            cout << "Nilai rata-rata = " << rata << endl;
        }
    } while (pilih != 5);
    return 0;
}