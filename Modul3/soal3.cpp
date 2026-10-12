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
