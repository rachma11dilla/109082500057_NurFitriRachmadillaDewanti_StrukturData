# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Nur Fitri Rachmadilla Dewanti - 109082500057</p>

## Dasar Teori

Code::Blocks adalah aplikasi yang digunakan untuk menulis, mengompilasi, dan menjalankan program, khususnya dalam bahasa C, C++, dan Fortran. Aplikasi ini bersifat gratis, open-source, dan dapat digunakan di berbagai sistem operasi. Code::Blocks juga menyediakan fitur untuk membantu pengguna dalam membuat program, seperti editor kode, proses build, run, serta pesan kesalahan yang dapat digunakan untuk mengetahui letak kesalahan pada program.

### A. Pengenalan Code::Blocks IDE dan Dasar Bahasa C++<br/>

Bagian ini membahas pengenalan Code::Blocks sebagai aplikasi untuk membuat dan menjalankan program serta dasar-dasar bahasa C++.

#### 1. Code::Blocks IDE

#### 2. Struktur Dasar dan Tipe Data C++

#### 3. Variabel dan Input/Output

### B. Operator dan Struktur Kendali dalam C++<br/>

Bagian ini membahas penggunaan operator dan struktur kendali yang digunakan untuk mengolah data serta mengatur jalannya program.

#### 1. Operator dalam C++

#### 2. Kondisional dan Perulangan

#### 3. Struktur dan Blok Program

## Guided

### 1. Menampilkan Teks

```C++
#include <iostream>
using namespace std;
int main () {
    cout<<"saya lagi belajar bahasa C++ nih!!!"<<endl;
    return 0;
}
```

Program ini digunakan untuk menampilkan kalimat “saya lagi belajar bahasa C++ nih!!!”. cout dipakai untuk menampilkan teks, kalau endl dipakai untuk membuat baris baru.


### 2. Input dan Output Bilangan Bulat

```C++
#include <iostream> 
using namespace std; 
int main(){ 
    int inp; 
    cin >> inp; 
    cout << "nilai = " << inp; 
    return 0; 
} 
```

Program ini digunakan untuk menerima input berupa bilangan, disimpan ke variabel inp, output berupa “nilai =”. cin dipakai untuk menerima input, jika cout dipakai untuk menampilkan hasilnya.


### 3. Menghitung Hasil Operasi Aritmatika

```C++
#include <iostream> 
using namespace std; 
int main(){ 
    int W, X, Y; float Z; 
    X = 7; Y = 3; W = 1; 
    Z = (X + Y)/(Y + W); 
    cout<< "Nilai z = " << Z << endl; 
    return 0; 
} 
```

Program ini digunakan untuk menghitung nilai Z dari hasil penjumlahan X + Y kemudian dibagi dengan Y + W. Nilai X, Y, dan W yaitu 7, 3, dan 1,hasil perhitungannya disimpan dalam variabel Z. Output berupa nilai Z.


### 4. Menghitung Diskon Pembelian Menggunakan Kondisi If-Else

```C++
#include <iostream> 
using namespace std; 
int main(){ 
    double tot_pembelian, diskon; 
    cout<<"total pembelian: Rp"; 
    cin>>tot_pembelian; 
    diskon = 0; 
    if(tot_pembelian >= 100000) 
        diskon = 0.05*tot_pembelian; 
    else  
       diskon = 0; 
    cout<<"besar diskon = Rp" <<diskon; 
} 
```

Program ini digunakan untuk menghitung besar diskon berdasarkan total pembelian. Jika total pembelian Rp100.000 atau lebih, maka mendapat diskon 5%, jika kurang dari Rp100.000, diskonnya Rp0. Output berupa diskon tsb.

### 5. Menentukan Hari Kerja dan Hari Libur Menggunakan Switch

```C++
#include <iostream>
using namespace std;
int main () {
    int kode_hari;
    puts("Menentukan hari kerja/libur\n");
    puts("1=Senin 3=Rabu 5=Jumat 7=Minggu ");
    puts("2=Selasa 4=Kamis 6=Sabtu");
    cin>>kode_hari;
    switch (kode_hari) {
        case 1:
        case 2:
        case 3: 
        case 4:
        case 5:
            cout << "Hari Kerja";
            break;
        case 6:
        case 7:
            cout << "Hari Libur";
            break;
        default:
            cout << "Kode masukkan salah!!!";       
    }
    return 0;
}
```

Program ini digunakan untuk menentukan apakah hari yang di input termasuk hari kerja/hari libur sesuai kode hari. Kode 1–5 sbg hari kerja, kode 6–7 sbg hari libur. Jika kode yang di input tdk sesuai, output nya yaitu kode masukkan salah.

### 6. Menampilkan Teks Menggunakan Perulangan For

```C++
#include <iostream> 
using namespace std; 
int main(){ 
    int jum; 
    cout<<"jumlah perulangan: "; 
    cin>>jum; 
    for(int i=0; i<jum; i++){ 
        cout<<"saya pintar\n"; 
    } 
    return 0; 
} 
```

Program ini digunakan untuk menampilkan kalimat “saya pintar” secara berulang sesuai jumlah perulangan yang di input. Perulangan for akan berjalan mulai dari i = 0 sampai sebelum mencapai nilai jum.


### 7. Menampilkan Baris Menggunakan Perulangan While

```C++
#include <iostream>
using namespace std;
int main () {
    int i=1;
    int jum;
    cout<<"masukkan banyak baris: ";        
    cin>>jum;
    while (i<=jum) {
        cout<<"baris ke-"<<i<<endl;
        i++; //sama dgn i=i+1
    }
    return 0;
}
```

Program ini digunakan untuk menampilkan "baris ke-" secara berulang sesuai jumlah baris yang di input. Program pakai perulangan while dimulai dari angka 1 dan terus berjalan selama nilai i kurang dari atau sama dengan jum. Nilai i akan bertambah 1 sampai jumlah baris yg di input.


### 8. Menampilkan Baris Menggunakan Perulangan Do-While

```C++
#include <iostream>
using namespace std;
int main () {
    int i=1;
    int jum;
    cin>>jum;
    do{
        cout<<"baris ke-" <<(i+1)<<endl;
        i++;
    } while (i<jum);
    return 0;
}    
```

Program ini digunakan untuk menampilkan "baris ke-" secara berulang sesuai jumlah yang di input. Program pakai perulangan do-while, menjalankan perintah dahulu sebelum memeriksa kondisi. Nilai i akan bertambah 1 dan program terus jalan selama nilai i kurang dari jum.

### 9. Menyimpan dan Menampilkan Data Siswa Menggunakan Struct

```C++
#include <iostream> 
#define MAX 5 
using namespace std; 
int main(){ 
    int i; 
    struct data{ 
        char nama[40]; 
        int nilai; 
    }; 
    data siswa[MAX]; 
    for(i=0; i<MAX; i++){ 
        cout<<"masukkan data ke"<<i+1<<endl; 
        cout<<"nama = "; 
cin>>siswa[i].nama; 
   cout<<"nilai = ";   
   cin>>siswa[i].nilai; 
    } 
    cout<<"\ndata siswa\n"; 
    cout<<"=======";
     for(i=0; i<MAX; i++){ 
        cout<<"\n\ndata ke-"<<i+1; 
        cout<<"\n\nnama ="<<siswa[i].nama; 
        cout<<"\n\nnilai ="<<siswa[i].nilai; 
    } 
    return 0; 
} 
```

Program ini digunakan untuk menyimpan dan menampilkan data 5 siswa yang terdiri dari nama dan nilai. struct untuk mengelompokkan data nama dan nilai, kemudian perulangan for dipakai untuk memasukkan dan menampilkan data setiap siswa.


## Unguided

### 1. Menghitung Operasi Aritmatika pada Dua Bilangan

```C++
#include <iostream>
using namespace std;
int main() {
    float a, b;

    cout << "bilangan pertama: ";
    cin >> a;

    cout << "bilangan kedua: ";
    cin >> b;

    cout << "penjumlahan = " << a + b << endl;
    cout << "pengurangan = " << a - b << endl;
    cout << "perkalian   = " << a * b << endl;
    cout << "pembagian   = " << a / b << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul1/output/soal1.png)


Program ini digunakan untuk menghitung dua bilangan bertipe float, kemudian program akan menghitung penjumlahan, pengurangan, perkalian, dan pembagian menggunakan operator aritmatika. Outputnya berupa Hasil dari setiap perhitungan tsb menggunakan cout.


### 2. Mengubah Angka Menjadi Bentuk Kalimat

```C++
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
```

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul1/output/soal2.png)


Program ini digunakan untuk mengubah angka dari 0 sampai 100 menjadi bentuk kalimat. Input berupa angka menggunakan cin. fungsi satuan() dan switch dipakai untuk mengubah angka satuan menjadi kata, seperti 1 menjadi "satu" dan 2 menjadi "dua". if-else dipakai untuk menentukan bentuk kata berdasarkan angka yang di input. Jika angka kurang dari 0 atau lebih dari 100, output berupa "Angka di luar jangkauan". Untuk angka 0, 10, 11, dan 100, program memiliki kondisi khusus. Angka belasan dan puluhan menggunakan pembagian (/) dan sisa bagi (%) agar hasil kalimat sesuai.


### 3. Membuat Pola Angka Berbentuk Cermin

```C++
#include <iostream>
using namespace std;
int main() {
    int n;

    cout << "Input: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int spasi = n; spasi > i; spasi--)
            cout << "  ";

        for (int j = i; j >= 1; j--)
            cout << j << " ";

        cout << "*";

        for (int j = 1; j <= i; j++)
            cout << " " << j;

        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 3_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul1/output/soal3.png)

Program ini digunakan untuk menampilkan pola angka berbentuk mirror berdasarkan angka yang di input. Program menggunakan perulangan for untuk mengatur spasi dan menampilkan angka secara menurun di sebelah kiri dan menaik di sebelah kanan tanda *.

## Kesimpulan

Berdasarkan praktikum Modul 1, saya jadi lebih memahami cara menggunakan Code::Blocks untuk membuat dan menjalankan program C++. Saya juga mempelajari beberapa dasar pemrograman, seperti penggunaan tipe data, variabel, input dan output, operator, kondisional, serta perulangan. Saya juga belajar menggunakan struct dan fungsi dalam program.
Dari latihan guided dan unguided, saya bisa mencoba langsung materi yang sudah dipelajari, seperti menghitung operasi aritmatika, menentukan diskon, membuat perulangan, mengubah angka menjadi kalimat, dan membuat pola angka.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>[3] Triase. (2020). Diktat Edisi Revisi: Struktur Data. Medan: Universitas Islam Negeri Sumatera Utara Medan.