# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>

<p align="center">Nur Fitri Rachmadilla Dewanti - 109082500057</p>

## Dasar Teori

Modul 3 membahas tentang Abstract Data Type (ADT). Materi yang dibahas yaitu pengertian ADT, jenis-jenis operasi dalam ADT, dan cara membuat program dengan memisahkan kode ke dalam beberapa file agar lebih rapi dan mudah dipahami.


### A. Abstract Data Type (ADT)<br/>

Abstract Data Type (ADT) adalah tipe data yang memiliki kumpulan operasi untuk mengolah data tersebut. ADT membantu program menjadi lebih rapi karena data dan operasi yang digunakan sudah memiliki fungsi masing-masing.

#### 1. Tipe Data ADT
Tipe data ADT digunakan untuk mengelompokkan beberapa data yang saling berhubungan. Dalam C++, ADT dapat dibuat menggunakan struct yang berisi beberapa variabel.

#### 2. Operasi Dasar ADT
Operasi dasar ADT adalah operasi yang digunakan untuk mengolah data, seperti membuat data baru, mengambil nilai, mengubah data, memeriksa data, dan menampilkan hasilnya.


### B. Jenis-Jenis Operasi ADT<br/>

Bagian ini membahas beberapa operasi yang digunakan untuk mengelola data dalam ADT.

#### 1. Konstruktor atau Kreator
Konstruktor/Kreator untuk membuat data baru.

#### 2. Selector
Selector digunakan untuk mengambil atau melihat nilai data.

#### 3. Prosedur Pengubah Nilai
Operasi ini digunakan untuk mengubah isi data.

#### 4. Validator
Validator digunakan untuk memeriksa apakah data sesuai aturan.

#### 5. Destruktor atau Dealokator
Destruktor atau dealokator digunakan untuk menghapus objek dan membebaskan memorinya.

#### 6. Operasi Input dan Output
Operasi input digunakan untuk menerima masukan dan menampilkan hasil.

#### 7. Operator Relasional dan Aritmatika
Operator relasional digunakan untuk membandingkan dua nilai. Operator aritmatika digunakan untuk melakukan perhitungan, seperti penjumlahan, pengurangan, perkalian, dan pembagian.

#### 8. Konversi Tipe Data
Konversi tipe data digunakan untuk mengubah tipe data ke tipe lainnya.


### C. Penerapan ADT dalam C++<br/>

ADT dalam C++ dapat dibuat dengan memisahkan deklarasi data, isi fungsi, dan program utama ke dalam beberapa file. Tujuannya agar kode lebih rapi dan mudah diperbaiki.

#### 1. File Header (.h)
File header digunakan untuk menuliskan deklarasi tipe data, fungsi, dan prosedur yang akan digunakan dalam program.

#### 2. File Implementasi (.cpp)
File implementasi digunakan untuk menuliskan isi dari fungsi dan prosedur yang sudah dideklarasikan pada file header.

#### 3. File Program Utama (main.cpp)
File program utama digunakan untuk menjalankan program dan memanggil fungsi atau prosedur yang sudah dibuat.

#### 4. Pemisahan File Program
Pemisahan file membuat program lebih teratur karena setiap file memiliki tugas masing-masing. Dengan begitu, kode lebih mudah dibaca, diperiksa, dan dikembangkan.


### D. Fungsi dan Prosedur dalam ADT<br/>

Fungsi dan prosedur digunakan untuk menjalankan perintah tertentu saat program berjalan.

#### 1. Fungsi
Fungsi adalah bagian program yang menjalankan tugas tertentu dan menghasilkan nilai balik. Contohnya, fungsi untuk menghitung rata-rata nilai mahasiswa.

#### 2. Prosedur
Prosedur adalah bagian program yang menjalankan tugas tertentu tanpa menghasilkan nilai balik. Dalam C++, prosedur biasanya menggunakan void. Contohnya, prosedur untuk menampilkan data mata pelajaran.

#### 3. Parameter Fungsi dan Prosedur
Parameter digunakan untuk mengirimkan data ke fungsi atau prosedur agar data tersebut dapat diolah sesuai dengan kebutuhan program.


## Guided

### 1. buku.h

```C++ //buku.h
#ifndef BUKU_H
#define BUKU_H
#include <iostream>

using namespace std;

struct buku 
{
    string judul;
    int halaman;
    string penulis;
};

void editIsi(string judul, int halaman, string penulis, buku &buku);
void tampilkanIisiBuku(buku buku);
bool checkPenulis(buku buku);

#endif
```

File buku.h digunakan untuk menyimpan data buku, yaitu judul, jumlah halaman, dan nama penulis. File ini berisi deklarasi 3 fungsi untuk mengisi data buku, menampilkan data buku, dan memeriksa apakah nama penulis masih kosong.


### 2. buku.cpp

```C++ //buku.cpp
#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku) 
{
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanIisiBuku(buku buku)
{
    cout << "Judul Buku : " << buku.judul << endl;
    cout << "Halaman : " << buku.halaman << endl;
    cout << "Penulis : " << buku.penulis << endl;
    
}

bool checkPenulis(buku buku)
{
    return buku.penulis == "";
}
```

File buku.cpp berisi isi dari fungsi-fungsi yang ada di buku.h. Fungsi editIsi() untuk mengisi atau mengubah data buku, tampilkanIsiBuku() untuk menampilkan data buku, dan checkPenulis() untuk mengecek apakah nama penulis kosong atau tidak.


### 3. main.cpp

```C++ //main.cpp
#include <iostream>
#include "buku.h"

using namespace std;

int main() 
{
    buku novel;
    string judul, penulis;
    int halaman;

    cout << "Masukkan nama judul buku : ";
    cin >> judul;
    cout << "Masukkan halaman buku : ";
    cin >> halaman;
    cout << "Masukkan penulis buku : ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilkanIisiBuku(novel);

    cout << checkPenulis(novel);

    return 0;
}
```

File main.cpp merupakan program utama untuk menjalankan ADT buku. Program meminta user untuk input data buku, lalu menyimpan dan menampilkan outputnya. Setelah itu, program memeriksa apakah nama penulis kosong atau tidak.


## Unguided

### 1. Pengolahan Nilai Akhir Mahasiswa

```C++
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
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul3/output/soal1_1.png)
![Screenshot Output Unguided 1_2](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul3/output/soal1_2.png)


Program ini digunakan untuk menyimpan data maksimal 10 mahasiswa ke dalam array, seperti nama, NIM, nilai UTS, nilai UAS, nilai tugas, dan nilai akhir.
Fungsi hitungNilai() digunakan untuk menghitung nilai akhir dengan rumus 30% nilai UTS, 40% nilai UAS, dan 30% nilai tugas. Setelah semua data di input, program menampilkan output data mahasiswa beserta nilai akhirnya.


### 2. Implementasi ADT Pelajaran

```C++ //pelajran.h
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```

```C++ //pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;

    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;

    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

```C++ //main.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);

    tampil_pelajaran(pel);

    return 0;
}
```

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul3/output/soal2_1.png)
![Screenshot Output Unguided 2_2](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul3/output/soal2_2.png)
![Screenshot Output Unguided 2_3](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul3/output/soal2_3.png)


Program ini digunakan untuk menerapkan konsep Abstract Data Type (ADT) pada data pelajaran. Data pelajaran terdiri dari nama mata pelajaran dan kode mata pelajaran.
File pelajaran.h berisi deklarasi data dan fungsi pelajaran.cpp berisi implementasi/isi fungsi. File main.cpp digunakan untuk membuat data pelajaran dengan fungsi create_pelajaran() dan menampilkan datanya melalui fungsi tampil_pelajaran().


### 3. Pertukaran Isi Array 2D dan Nilai Pointer

```C++
#include <iostream>
using namespace std;

// menampilkan
void tampil(int a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// menukar posisi [0] [0]
void tukarArray(int a[3][3], int b[3][3]) {
    int temp = a[0][0];
    a[0][0] = b[0][0];
    b[0][0] = temp;
}

// menukar nilai dgn pointer
void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int x = 5, y = 10;
    int *p1 = &x;
    int *p2 = &y;

    cout << "Array A sebelum ditukar:\n";
    tampil(A);

    cout << "\nArray B sebelum ditukar:\n";
    tampil(B);

    tukarArray(A, B);

    cout << "\nArray A setelah ditukar:\n";
    tampil(A);

    cout << "\nArray B setelah ditukar:\n";
    tampil(B);

    cout << "\nNilai sebelum ditukar:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    tukarPointer(p1, p2);

    cout << "\nNilai setelah ditukar:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;

    return 0;
}
```

### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 3_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul3/output/soal3_1.png)
![Screenshot Output Unguided 3_2](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul3/output/soal3_2.png)

Program ini digunakan untuk menampilkan dan menukar isi dua array 2D berukuran 3×3 serta menukar nilai menggunakan dua pointer integer.
Program memiliki 3 fungsi, yaitu tampil() untuk menampilkan isi array, tukarArray() untuk menukar nilai array A dan B pada posisi [0][0], dan tukarPointer() untuk menukar nilai variabel x dan y menggunakan pointer.
Pada program utama, array A dan B diisi dengan angka yang berbeda. Setelah itu, program menampilkan isi array dan nilai variabel sebelum dan sesudah ditukar

## Kesimpulan

Berdasarkan praktikum Modul 3, saya jadi lebih memahami konsep ADT dalam C++. Saya belajar cara mengelompokkan data menggunakan struct, membuat fungsi dan prosedur, serta memisahkan program ke dalam beberapa file. Melalui latihan yang dikerjakan, saya juga lebih memahami cara mengolah data mahasiswa, membuat ADT buku dan pelajaran, serta menukar isi array dan nilai menggunakan pointer.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.