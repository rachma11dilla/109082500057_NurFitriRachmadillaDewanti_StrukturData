# <h1 align="center">Laporan Praktikum Modul 4 - SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>

<p align="center">Nur Fitri Rachmadilla Dewanti - 109082500057</p>

## Dasar Teori

Modul 4 membahas tentang Singly Linked List. Materi ini membahas pengertian linked list, komponen penyusunnya, operasi dasar, dan penerapannya dalam program C++ menggunakan beberapa file.


### A. Singly Linked List<br/>

Struktur data yang terdiri dari beberapa elemen yang saling terhubung menggunakan pointer. Setiap elemen menyimpan data dan alamat elemen berikutnya. Elemen terakhir menunjuk ke Nil karena tidak memiliki elemen lanjutan.

#### 1. Komponen Singly Linked List
Info: Menyimpan data pada setiap elemen.
Next: Menunjuk ke elemen berikutnya.
First: Menunjuk ke elemen pertama dalam list.
Nil: Menandakan pointer tidak menunjuk ke elemen mana pun.


### B. Operasi Dasar Singly Linked List<br/>

Operasi dasar Singly Linked List digunakan untuk mengelola data dalam list.

#### 1. Create List
Digunakan untuk membuat list kosong dengan mengatur first menjadi Nil.

#### 2. Alokasi dan Dealokasi
Alokasi digunakan untuk menyediakan memori bagi elemen baru, sedangkan dealokasi digunakan untuk membebaskan memori yang sudah tidak digunakan.

#### 3. Insert First
digunakan untuk menambahkan data baru di bagian awal list. Data baru akan menunjuk ke elemen pertama sebelumnya, kemudian posisi first dipindahkan ke data yang baru ditambahkan.

#### 4. Print Info
Digunakan untuk menampilkan seluruh data dalam list dengan menelusuri elemen mulai dari first hingga Nil.


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

#endif

```

File list.h digunakan untuk mendeklarasikan struktur data dan fungsi yang akan digunakan dalam program Singly Linked List. Yang terdapat data mahasiswa berupa nama, NIM, dan umur, serta struktur node yang menghubungkan setiap data mahasiswa.


### list.cpp

```C++ 
#include "list.h"
#include <iostream>
using namespace std;

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

void createList(linkedlist &List)
{
    {
        /* I.S. sembarang
        F.S. terbentuk list kosong */
        List.first = NIL;
    }
}

address alokasi(string nama, string nim, int umur)
{
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
}

void dealokasi(address &node)
{
        /* I.S. P terdefinisi
        F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = NIL;
    delete node;
}

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
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != NIL && nodePrev->next !=NIL)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = NIL;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist list)
{
    if (isEmpty(list) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = list.first;
        while (nodeBantu != NIL)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist list)
{
    int count = 0;
    address nodeBantu = list.first;
    while (nodeBantu != NIL)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedlist &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;
    while (nodeBantu != NIL)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = NIL;
    cout << "List sudah terhapus." << endl;
}
```

File list.cpp digunakan untuk menuliskan proses kerja dari fungsi-fungsi yang sudah dideklarasikan di list.h. Fungsi ini digunakan untuk membuat list, menambahkan data mahasiswa, menghapus data, menampilkan isi list, dan menghitung jumlah node.


### main.cpp

```C++ 
#include "list.h"
using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = NIL;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
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

    delFirst(List);
}
```

File main.cpp digunakan untuk menjalankan program dengan memanggil fungsi-fungsi yang telah dibuat. Program ini memasukkan data mahasiswa, menampilkan data, dan menghitung jumlah node dalam list.



## Unguided

### singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
#define Nil NULL

using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

### singlylist.cpp

```C++
#include "singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    if (P != Nil) {
        delete P;
        P = Nil;
    }
}

void printInfo(List L) {
    address P = L.first;

    while (P != Nil) {
        cout << P->info;

        if (P->next != Nil) {
            cout << " ";
        }
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (P != Nil) {
        P->next = L.first;
        L.first = P;
    }
}
```

### main.cpp

```C++
#include "singlylist.h"

int main() {
    List L;
    address P1 = Nil, P2 = Nil, P3 = Nil;
    address P4 = Nil, P5 = Nil;

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

    printInfo(L);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul4/output/latihan1.png)


Program ini dibuat untuk menyimpan dan menampilkan beberapa angka menggunakan struktur data Singly Linked List. Program ini menggunakan tiga file, yaitu Singlylist.h, Singlylist.cpp, dan main.cpp. Angka yang dimasukkan yaitu 2, 0, 8, 12, dan 9 menggunakan fungsi insertFirst. Karena setiap angka baru dimasukkan ke bagian depan list, hasil outputnya menjadi 9, 12, 8, 0, 2.


## Kesimpulan

Berdasarkan praktikum Modul 4, saya jadi lebih memahami cara kerja Singly Linked List serta penggunaan pointer dalam mengelola data, dan pembagian program menjadi beberapa file juga membuat kode lebih rapi. Singly Linked List merupakan struktur data yang menggunakan pointer untuk menghubungkan setiap elemen. Setiap elemen menyimpan data dan alamat elemen berikutnya. Di Singly Linked List, ada beberapa operasi yang dapat digunakan, yaitu membuat list, menambahkan data, menampilkan data, menghapus data, dan mengubah data.


## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] GeeksforGeeks. (2026). “Singly Linked List Tutorial”. Diakses pada 19 Oktober 2026 melalui https://www.geeksforgeeks.org/dsa/singly-linked-list-tutorial/
<br>[4] Modul 4: Singly Linked List (Bagian Pertama). Modul Praktikum Struktur Data, hlm. 36–46.