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