#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilai(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int jumlah;

    cout << "Jumlah mahasiswa (maksimal 10): ";
    cin >> jumlah;

    if (jumlah < 1 || jumlah > 10) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 0;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i + 1 << endl;

        cout << "Nama: ";
        getline(cin >> ws, mhs[i].nama);

        cout << "NIM: ";
        cin >> mhs[i].nim;

        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;

        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;

        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilai(
            mhs[i].uts, mhs[i].uas, mhs[i].tugas
        );
    }

    cout << "\n=== DATA MAHASISWA ===\n";

    for (int i = 0; i < jumlah; i++) {
        cout << "\nNama: " << mhs[i].nama << endl;
        cout << "NIM: " << mhs[i].nim << endl;
        cout << "Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }
    return 0;
}
