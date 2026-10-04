# <h1 align="center">Laporan Praktikum Modul 2 - Array, Pointer, Fungsi/Prosedur, dan Parameter</h1>

<p align="center">Nur Fitri Rachmadilla Dewanti - 109082500057</p>

## Dasar Teori

Modul 2 membahas beberapa konsep dalam bahasa C++ yang digunakan untuk mengolah dan mengatur data dalam program. Materi yang dibahas meliputi array, pointer dan alamat memori, hubungan pointer dengan array dan string, fungsi, prosedur, serta cara melewatkan parameter menggunakan call by value, call by pointer, dan call by reference.


### A. Array dalam C++<br/>

Array merupakan kumpulan data dengan nama yang sama dan setiap elemen bertipe data sama. Untuk mengakses setiap komponen/elemen array berdasarkan indeks dari setiap elemen.

#### 1. Array Satu Dimensi
Array yang hanya terdiri dari satu larik data saja.

#### 2. Array Dua Dimensi
Array dua dimensi digunakan untuk menyimpan data dalam bentuk tabel yang terdiri dari baris dan kolom. Setiap data diakses menggunakan dua indeks, yaitu indeks baris dan kolom.

#### 3. Array Berdimensi Banyak
Array yang mempunyai indeks banyak, lebih dari dua. Indeks inilah yang menyatakan dimensi array.

### B. Pointer dan Alamat Memori<br/>

Bagian ini membahas konsep alamat memori dan pointer yang digunakan untuk menyimpan alamat dari variabel lain.

#### 1. Data dan Memori
Data dan memori adalah tempat penyimpanan data program di RAM. Setiap lokasi memori memiliki alamat unik, dan sistem operasi mengalokasikan ruang memori untuk variabel, objek, atau array saat program berjalan.

#### 2. Pointer dan Alamat
Pointer adalah variabel yang digunakan untuk menyimpan alamat memori variabel lain sehingga dapat mengakses nilainya.

#### 3. Pointer dan Array
Pointer memiliki hubungan yang erat dengan array. Pointer dapat digunakan untuk menunjuk alamat elemen array dan mengakses isi dari elemen tersebut.

#### 4. Pointer dan String
String dalam C++ dapat berupa kumpulan karakter atau array karakter. Pointer dapat digunakan untuk menunjuk karakter pada string dan mengakses data string melalui alamat memorinya.

### C. Fungsi dan Prosedur dalam C++<br/>

Bagian ini membahas penggunaan fungsi dan prosedur untuk membuat program menjadi lebih terstruktur serta mengurangi pengulangan kode.

#### 1. Fungsi
Fungsi merupakan blok kode yang dibuat untuk menjalankan tugas tertentu. Fungsi dapat menerima parameter dan menghasilkan nilai balik yang dapat digunakan dalam program.

#### 2. Prosedur
Prosedur merupakan fungsi yang tidak mengembalikan nilai. Dalam C++, prosedur dikenal sebagai fungsi `void` dan digunakan untuk melakukan tugas tertentu tanpa menghasilkan nilai balik.

### D. Parameter Fungsi<br/>

Bagian ini membahas parameter yang digunakan untuk mengirimkan data ke dalam fungsi.

#### 1. Paramater Formal dan Parameter Aktual
Variabel yang ada pada daftar paramerter ketika mendefinisikan fungsi. Pada fungsi maks3() contoh di atas, a, b dan merupakan parameter formal.

#### 2. Call by value
Cara melewatkan nilai parameter dengan menyalin nilai dari parameter aktual ke parameter formal. Perubahan pada parameter formal tidak mengubah variabel aslinya.

#### 3. Call by pointer
Cara melewatkan alamat suatu variabel ke dalam fungsi. Dengan cara ini, perubahan yang dilakukan melalui pointer dapat mengubah nilai variabel aslinya.

#### 4. Call by Reference
Cara melewatkan alamat suatu variabel melalui referensi. Perubahan pada parameter di dalam fungsi akan memengaruhi variabel aslinya.


## Guided

### 1. Array

```C++
#include <iostream>
#define MAX 5
using namespace std;
int main(){
    int i,j;
    float nilai_total, rata_rata;
    float nilai[MAX];
    static int nilai_tahun[MAX][MAX]=
    {   {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };

/*inisialisasi array dua dimensi */
    for (i=0; i<MAX; i++){
        cout<<"masukkan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    cout<<"\ndata nilai siswa :\n";

/*menampilkan array satu dimensi */
    for (i=0; i<MAX; i++)
        cout<<"nilai k-"<<i+1<<"=" <<nilai[i]<<endl;
    cout<<"\n nilai tahunan : \n";
    
/* menampilkan array dua dimensi */
    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++)
            cout<<nilai_tahun[i][j];
        cout<<"\n";
    }
    return 0;
}
```

Program ini digunakan untuk menginput dan menampilkan nilai siswa menggunakan array satu dimensi, dan menampilkan data nilai tahunan menggunakan array dua dimensi.


### 2. Pointer

```C++
#include <iostream>
using namespace std;
int main(){
    int x, y; // x dan y bertipe int
    int *px; // px merupakan variabel pointer menunjuk ke variabel int

    x = 87;
    px = &x;
    y = *px;
    
    cout << "Alamat x= " << &x << endl;
    cout << "Isi px= " << px << endl;
    cout << "Isi X= " << x << endl;
    cout << "Nilai yang ditunjuk px= " << *px << endl;
    cout << "Nilai y= " << y << endl;
    return 0;
}
```

Program ini digunakan untuk menunjukkan fungsi pointer di C++, yaitu untuk menyimpan alamat memori variabel dan mengakses nilai yang ditunjuk oleh pointer tersebut. 


### 3. Function

```C++
#include <iostream>
using namespace std;
int maks3(int a, int b, int c);
int main(){
    int x,y,z;
    cout<<"masukkan nilai bilangan ke-1 =";
    cin>>x;
    cout<<"masukkan nilai bilangan ke-2 =";
    cin>>y;
    cout<<"masukkan nilai bilangan ke-3 =";
    cin>>z;
    cout<<"nilai maksimumnya adalah =" <<maks3(x,y,z);
    return 0;
}
int maks3(int a, int b, int c){
    int temp_max =a;
    if(b>temp_max)
    temp_max=b;
    if(c>temp_max)
    temp_max=c;
    return (temp_max);
}
```

Program ini digunakan untuk mencari dan menampilkan nilai maksimum drai tiga bilangan yang di input dengan menggunakan function -> maks3.


### 4. Procedure

```C++
#include <iostream>
using namespace std;

void tulis(int x);
int main() {
    int jum;
    cout << "jumlah baris kata= ";
    cin >> jum;
    tulis(jum);
    return 0;
}

void tulis(int x){
    for (int i=0;i<x;i++)
        cout<<"baris ke-" <<i+1 << endl;
}
```

Program ini digunakan untuk menampilkan baris kata sesuai jumlah yang di input dengan menggunakan procedure -> void tulis(int x).

### 5. Parameter Fungsi

```C++
#include <iostream>
using namespace std;

// 1. Call by Value: variabel asli TIDAK berubah
void tukarValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// 2. Call by Pointer: variabel asli IKUT berubah (pakai *)
void tukarPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. Call by Reference: variabel asli IKUT berubah (pakai &)
void tukarReference(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4, b = 6;

    // Tes Call by Value
    tukarValue(a, b);
    cout << "Setelah Call by Value     -> a = " << a << ", b = " << b << " (Tetap)" << endl;

    // Tes Call by Pointer (kirim alamatnya pakai &)
    tukarPointer(&a, &b);
    cout << "Setelah Call by Pointer   -> a = " << a << ", b = " << b << " (Berubah!)" << endl;

    // Tes Call by Reference (mengembalikan posisi semula)
    tukarReference(a, b);
    cout << "Setelah Call by Reference -> a = " << a << ", b = " << b << " (Berubah lagi!)" << endl;

    return 0;
}
```

Program ini digunakan untuk membandingkan cara kerja Call by Value, Call by Pointer, dan Call by Reference dalam menukar nilai dua variabel.


## Unguided

### 1. Matriks (Penjumlahan, Pengurangan, Perkalian)

```C++
#include <iostream>
using namespace std;
const int N = 3;
int main() {
    int A[N][N], B[N][N], Hasil[N][N];

    cout << "Matriks A:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Matriks B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> B[i][j];
        }
    }

    // penjumlahan
    cout << "\nHasil Penjumlahan:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Hasil[i][j] = A[i][j] + B[i][j];
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }

    // pengurangan
    cout << "\nHasil Pengurangan:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Hasil[i][j] = A[i][j] - B[i][j];
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }

    // perkalian
    cout << "\nHasil Perkalian:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Hasil[i][j] = 0;
            for (int k = 0; k < N; k++) {
                Hasil[i][j] += A[i][k] * B[k][j];
            }
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul2/output/soal1.png)


Program ini digunakan untuk melakukan operasi pada dua matriks a dan b berukuran 3x3 (penjumlahan, pengurangan, perkalian). Input berupa elemen matriks a dan b, kemudian program menghitung setiap operasi menggunakan perulangan dan menyimpan hasilnya di matriks "Hasil". Output berupa hasil dari penjumlahan, pengurangan, dan perkalian dari kedua matriks.


### 2. Pointer dan Reference (Menukar nilai 3 variabel)

```C++
#include <iostream>
using namespace std;

// pointer
void tukarPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

// reference
void tukarReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int a = 50, b = 60, c = 70;

    cout << "Sebelum ditukar: " << a << " " << b << " " << c << endl;

    tukarPointer(&a, &b, &c);
    cout << "Setelah pointer: " << a << " " << b << " " << c << endl;

    a = 50;
    b = 60;
    c = 70;

    tukarReference(a, b, c);
    cout << "Setelah reference: " << a << " " << b << " " << c << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul2/output/soal2_1.png)
![Screenshot Output Unguided 2_2](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul2/output/soal2_2.png)


Program ini digunakan untuk menukar nilai dari 3 variabel (a, b, c) menggunakan pointer dan reference. Percobaan pertama saya menggunakan nilai awal 10, 20, 30. Kemudian, program menukar nilai ketiga variabel menggunakan pointer dan reference. Setelah itu, saya mengubah nilai awal menjadi 50, 60, 70. Hasilnya tetap menunjukkan bahwa kedua metode dapat menukar nilai ketiga variabel.


### 3. Array Satu Dimensi

```C++
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
```

### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 3_1](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul2/output/soal3_1.png)
![Screenshot Output Unguided 3_2](https://github.com/rachma11dilla/109082500057_NurFitriRachmadillaDewanti_StrukturData/blob/main/Modul2/output/soal3_2.png)

Program ini digunakan untuk mencari nilai maksimum, minimum, dan rata-rata dari sebuah array. Array sudah ada di kode yaitu (48, 2, 7, 21, 5, 20, 77, 9, 10, 1). Kemudian, program akan mencari nilai maksimum dan minumum menggunakan fungsi, dan menghitung rata0rata menggunakan prosedur. User bisa memilih menu sesuai perhitungan yang di inginkan.

## Kesimpulan

Berdasarkan praktikum Modul 2, saya jadi lebih memahami mengenai array, pointer, fungsi, prosedur, dan parameter di C++. Dari guided dan unguided, saya mengerti jika array bisa digunakan untuk melakukan operasi pada matriks, mencari nilai maksimum, minimum, dan rata-rata. Pointer dan reference juga bisa digunakan untuk mengubah nilai variabel menggunakan fungsi. Tugas praktikum ini membuat saya lebih paham mengenai perbedaan cara kerja pointer dan reference dalam C++.

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.