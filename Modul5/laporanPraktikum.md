# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>

<p align="center">Nur Fitri Rachmadilla Dewanti - 109082500057</p>

## Dasar Teori

Modul 5 membahas tentang Singly Linked List (Bagian Kedua). Materi ini merupakan lanjutan dari pembahasan Singly Linked List (Bagian Pertama), dengan fokus pada pencarian elemen, pengelolaan data, dan penerapannya dalam program C++.


### A. Searching pada Singly Linked List<br/>

Searching adalah proses mencari data tertentu di dalam linked list dengan memeriksa setiap elemen mulai dari First sampai data ditemukan atau mencapai Nil.

#### 1. Fungsi findElm
Digunakan untuk mencari elemen berdasarkan nilainya. Jika ditemukan, fungsi mengembalikan alamat elemen tersebut. Jika tidak, fungsi mengembalikan Nil.

#### 2. Fungsi fFindElm
Digunakan untuk mengecek apakah alamat suatu elemen ada di dalam list. Hasilnya true jika ada dan false jika tidak ada.

#### 3. Fungsi findBefore
Digunakan untuk mencari elemen yang berada sebelum elemen tertentu. Jika elemen tersebut berada di awal list, hasilnya Nil.


### B. Operasi Pengelolaan Singly Linked List<br/>

Selain pencarian, terdapat beberapa operasi lain yang digunakan untuk mengelola elemen dalam linked list.

#### 1. Insert dan Delete
Fungsi insertFirst, insertAfter, dan insertLast digunakan untuk menambahkan elemen di awal, setelah elemen tertentu, dan di akhir list. Sementara itu, delFirst, delLast, delAfter, dan delP digunakan untuk menghapus elemen dari list.

#### 2. Print Info dan nbList
Digunakan untuk menampilkan semua data dalam list. Fungsi nbList digunakan untuk menghitung jumlah elemen dalam list.

#### 3. DelAll, InvertList, dan CopyList
Fungsi delAll digunakan untuk menghapus semua elemen dalam list. Fungsi invertList digunakan untuk membalik urutan elemen, sedangkan copyList digunakan untuk menyalin list.


### C. Penerapan dalam C++<br/>

Program Singly Linked List dibagi menjadi tiga file, yaitu:

#### 1. File Header (.h)
Berisi deklarasi struktur data dan prototype fungsi.

#### 2. File Implementasi (.cpp)
Berisi kode fungsi untuk mengelola linked list.

#### 3. File Program Utama (main.cpp)
Digunakan untuk menjalankan program dan menampilkan hasilnya.



## Guided

### list.h

```C++ 
#ifndef List_h
#define List_h
#define NIL nullptr

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

//Tambahan - Minggu 6
void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist &list, address &prev);
void updateByNim(linkedlist &list, string nim);

address findNodeByData(linkedlist List, string data);

//Minggu 6
// ---- TAMBAHAN FITUR SEARCHING ---
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, string node);
void FindNodeByRange(linkedlist list, int nilaiAwal, int nilaiAkhir);

#endif
```

File list.h berisi deklarasi data mahasiswa, node, linked list, dan fungsi yang digunakan dalam program.


### list.cpp

```C++ 
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == NIL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = NIL;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = NIL;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = NIL;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != NIL)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != NIL)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = NIL;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == NIL)
        {
            List.first->next = NIL;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != NIL)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = NIL;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != NIL && nodePrev->next != NIL)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = NIL;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != NIL)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != NIL)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != NIL)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = NIL;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;
    list.first->isidata = newData;
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list))
    {
        cout << "List Kosong!" << endl;
    }
    else
    {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

    address nodeBantu = list.first;
    while (nodeBantu->next != NIL)
    {
        nodeBantu = nodeBantu->next;
    }
    nodeBantu->isidata = newData;

    }
}

void updateAfter(linkedlist &list, address &prev)
{
    if (isEmpty(list))
    {
        cout << "List Kosong!" << endl;
    }
    else
    {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

        prev->next->isidata = newData;
    }
}    

// //tambahan
void updateByNim(linkedlist &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = findNodeByData(list, nim);

        if (nodeBantu != NIL)
        {
            dataMahasiswa newData;
            cout << "Masukan nama baru : ";
            cin >> newData.nama;
            cout << "Masukan nim baru : ";
            cin >> newData.nim;
            cout << "Masukan umur baru : ";
            cin >> newData.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address findNodeByData(linkedlist List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != NIL)
        {
            posisi++;
            if (nodeBantu->isidata.nama == data || nodeBantu->isidata.nim == data)
            {
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return NIL;
}

void FindNodeByAddress(linkedlist List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != NIL)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != NIL)
        {
            posisi++;
            int umur = nodeBantu->isidata.umur;
            if (umur >= nilaiAwal && umur <= nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
    cout << endl;
}
```

File list.cpp berisi kode untuk menjalankan fungsi-fungsi linked list seperti membuat list, menambahkan dan menghapus node, menampilkan data, menghitung jumlah node, mencari data, serta memperbarui data mahasiswa.


### main.cpp

```C++ 
#include "list.h"
#include <iostream>
using namespace std;

int main(){
		linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    // updateFirst(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    // printList(List);

    // updateLast(List);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    // printList(List);

    // updateAfter(List, nodeC);
    // cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER NODE C ---" << endl;
    // printList(List);

    updateByNim(List, "2211110014");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);

    return 0;
}
```

File main.cpp merupakan program utama yang digunakan untuk menjalankan program. Program ini membuat list, memasukkan lima data mahasiswa, menampilkan data dan jumlah node, serta mengubah data mahasiswa berdasarkan NIM. printList(List) untuk menampilkan judul dan isi linked list terbaru.
1. updateFirst(List); -> Bagian ini digunakan untuk memperbarui data mahasiswa pada node pertama.
2. updateLast(List); -> Bagian ini digunakan untuk memperbarui data mahasiswa pada node terakhir.
3. updateAfter(List, nodeC); -> Bagian ini digunakan untuk memperbarui data mahasiswa pada node setelah nodeC.
4. updateByNim(List, "2211110014"); -> Bagian ini menjalankan fungsi updateByNim() untuk mencari mahasiswa berdasarkan NIM 2211110014, yaitu Arvin pada data awal.



## Unguided

### singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#define Nil nullptr

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif
```

### singlylist.cpp

```C++
#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

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

int totalInfo(List L) {
    int total = 0;
    address P = L.First;

    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }

    return total;
}
```

### main.cpp

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    address cari;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "--- Output Singlylist ---" << endl;
    cout << "Isi linked list: ";
    printInfo(L);
    cout << endl;

    cout << "--- Output pencarian 8 ---" << endl;
    cari = findElm(L, 8);

    if (cari != Nil) {
        cout << cari->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }
    cout << endl;

    cout << "--- Output total info elemen ---" << endl;
    cout << "Total info dari kelima elemen adalah "
         << totalInfo(L) << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul5/output/latihan1.png)


Program ini menggunakan tiga file, yaitu singlylist.h, singlylist.cpp, dan main.cpp.
File singlylist.h berisi deklarasi struktur data dan fungsi yang digunakan.
File singlylist.cpp berisi kode untuk membuat list kosong, membuat node baru, menampilkan data, menambahkan node di awal list, mencari nilai, dan menghitung total nilai seluruh elemen.
File main.cpp, Pertama, program memasukkan angka 2, 0, 8, 12, dan 9 ke dalam list menggunakan fungsi insertFirst(). Karena data dimasukkan dari depan, urutannya menjadi 9, 12, 8, 0, dan 2. Setelah itu, program mencari angka 8 menggunakan fungsi findElm() dan menghitung total semua angka menggunakan fungsi totalInfo(). Hasilnya, angka 8 ditemukan dan total seluruh nilainya adalah 31.


## Kesimpulan

Berdasarkan praktikum Modul 5, saya belajar cara membuat dan menggunakan Singly Linked List di C++. Data yang diinput menggunakan fungsi insertFirst() urutannya menjadi 9, 12, 8, 0, 2. Saya juga belajar mencari angka 8 menggunakan findElm() dan menghitung jumlah seluruh angka menggunakan totalInfo() hasilnya 31.
Dengan latihan ini, saya jadi lebih memahami cara menambahkan data, mencari data, dan menghitung total nilai di linked list.


## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] GeeksforGeeks. (2026). “Singly Linked List Tutorial”. Diakses pada 19 Oktober 2026 melalui https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/
<br>[4] Modul 4: Singly Linked List (Bagian Pertama). Modul Praktikum Struktur Data, hlm. 36–46.