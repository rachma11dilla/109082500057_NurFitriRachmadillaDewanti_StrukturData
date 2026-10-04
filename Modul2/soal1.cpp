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