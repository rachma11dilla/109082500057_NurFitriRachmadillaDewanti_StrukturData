#include "singlylist.h"

// Membuat list kosong
void createList(List &L) {
    L.First = Nil;
}

// Membuat node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// Menghapus node dari memori
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// Menampilkan semua data dalam list
void printInfo(List L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Menambahkan node di awal list
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

// Mencari node berdasarkan nilainya
address findElm(List L, infotype x) {
    address P = L.First;

    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }

    return Nil;
}

// Menghitung jumlah seluruh nilai dalam list
int totalInfo(List L) {
    int total = 0;
    address P = L.First;

    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }

    return total;
}