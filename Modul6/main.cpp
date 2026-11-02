#include "Doublylist.h"
int main() {
    List L;
    CreateList(L);
    infotype data;
    address P;

    // SOAL 1: Input Data Kendaraan 
    cout << "=== INPUT DATA KENDARAAN ===" << endl;

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> data.nopol;

        cout << "masukkan warna kendaraan: ";
        cin >> data.warna;

        cout << "masukkan tahun kendaraan: ";
        cin >> data.thnBuat;

        // Cek nomor polisi
        if (findElm(L, data) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl << endl;
        } else {
            P = alokasi(data);
            insertLast(L, P);
            cout << endl;
        }
    }

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    // SOAL 2: Mencari Elemen D001 
    infotype cari = {};

    cout << "\nMasukkan Nomor Polisi yang dicari : ";
    cin >> cari.nopol;

    address found = findElm(L, cari);

    if (found != Nil) {
        cout << "\nNomor Polisi : " << found->info.nopol << endl;
        cout << "Warna        : " << found->info.warna << endl;
        cout << "Tahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    // SOAL 3: Menghapus Elemen D003 
    infotype hapus = {};

    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> hapus.nopol;

    address target = findElm(L, hapus);
    address H = Nil;

    if (target != Nil) {
        if (target == L.first) {
            deleteFirst(L, H);
        } else if (target == L.last) {
            deleteLast(L, H);
        } else {
            deleteAfter(target->prev, H);
        }

        dealokasi(H);

        cout << "Data dengan nomor polisi "
             << hapus.nopol << " berhasil dihapus." << endl;
    } else {
        cout << "Data tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST 1" << endl;
    printInfo(L);

    // Membersihkan sisa elemen
    while (L.first != Nil) {
        deleteFirst(L, H);
        dealokasi(H);
    }

    return 0;
}