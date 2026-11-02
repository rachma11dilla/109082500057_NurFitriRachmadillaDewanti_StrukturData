#include "Doublylist.h"

// list kosong
void CreateList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

// elemen baru
address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

// hapus elemen dari memori
void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

// masukkan elemen di akhir list
void insertLast(List &L, address P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

// nampilkan informasi kendaraan
void printInfo(List L) {
    address P = L.last;

    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;

        P = P->prev;
    }
}

// SOAL 2: Mencari elemen berdasarkan nomor polisi
address findElm(List L, infotype x) {
    address P = L.first;

    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }

        P = P->next;
    }

    return Nil;
}

// SOAL 3: Menghapus elemen pertama
void deleteFirst(List &L, address &P) {
    if (L.first == Nil) {
        P = Nil;
    } else {
        P = L.first;

        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = L.first->next;
            L.first->prev = Nil;
        }

        P->next = Nil;
        P->prev = Nil;
    }
}

// SOAL 3: Menghapus elemen terakhir
void deleteLast(List &L, address &P) {
    if (L.last == Nil) {
        P = Nil;
    } else {
        P = L.last;

        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = L.last->prev;
            L.last->next = Nil;
        }

        P->next = Nil;
        P->prev = Nil;
    }
}

// SOAL 3: Menghapus elemen setelah Prec
void deleteAfter(address Prec, address &P) {
    if (Prec == Nil || Prec->next == Nil) {
        P = Nil;
    } else {
        P = Prec->next;
        Prec->next = P->next;

        if (P->next != Nil) {
            P->next->prev = Prec;
        }

        P->next = Nil;
        P->prev = Nil;
    }
}