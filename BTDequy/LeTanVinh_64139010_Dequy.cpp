#include <iostream>
#include <math.h>
using namespace std;

// Hàm Fibonacci t?i uu v?i memoization
long fibo(int n, long memo[]) {
    if (n == 0 || n == 1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibo(n - 1, memo) + fibo(n - 2, memo);
    return memo[n];
}

// Bài 1
float S1(int n) {
    if (n == 1) return 1;
    return S1(n - 1) + float(1) / n;
}

// Bài 2
int S2(int n) {
    if (n == 1) return 3;
    return S2(n - 1) * (2 * n + 1);
}

// Bài 3
int S3(int n) {
    if (n == 1) return 1;
    return S3(n - 1) + pow(-1, n + 1) * n;
}

// Hàm giai th?a d? quy
int giaithua1(int n) {
    if (n == 1) return 1;
    return n * giaithua1(n - 1);
}

// Hàm giai th?a thông thu?ng
int giaithua(int n) {
    int S = 1;
    for (int i = 1; i <= n; i++) {
        S *= i;
    }
    return S;
}

// Bài 4
int S4(int n) {
    if (n == 1) return 1;
    return S4(n - 1) + giaithua(n);
}

// Bài 5
int S5(int n) {
    if (n == 0) return 0;
    return 1 + S5(n / 10);
}

// Bài 6
int USCLN(int a, int b) {
    if (b == 0) return a;
    return USCLN(b, a % b);
}

int BSCNN(int a, int b) {
    return (a * b) / USCLN(a, b);
}

// Bài 7
int S7(int X, int a, int b, int N) {
    if (N < 1) return X;
    if (N % 10 == 0) return S7(X, a, b, N - 1) + a + b;
    return S7(X, a, b, N - 1) + a;
}

// Bài 8
int S8(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return pow(S8(n - 1) + S8(n - 2), 2) + pow(S8(n - 1) - S8(n - 2), 2);
}

// Bài 9
int X(int n);
int Y(int n);

int X(int n) {
    if (n == 0) return 1;
    return 2 * X(n - 1) + 3 * Y(n - 1);
}

int Y(int n) {
    if (n == 0) return 1;
    return 3 * X(n - 1) - 2 * Y(n - 1);
}

// Bài 10
int S10(int n) {
    if (n == 0) return 1;
    int S = 0;
    for (int i = 0; i < n; i++) {
        S += giaithua1(n - i) * S10(i);
    }
    return S;
}

// Hàm main
int main() {
    int n;
    cout << "Nhap n so nguyen: ";
    cin >> n;

    while (true) {
        cout << "\nChon truong hop (1-10, 0 d? thoát): ";
        int m;
        cin >> m;

        if (m == 0) break;

        switch (m) {
            case 1: {
                long memo[n + 1];
                fill(memo, memo + n + 1, -1);
                cout << "Fibonacci(" << n << ") = " << fibo(n, memo) << endl;
                break;
            }
            case 2:
                cout << "S1(" << n << ") = " << S1(n) << endl;
                break;
            case 3:
                cout << "S2(" << n << ") = " << S2(n) << endl;
                break;
            case 4:
                cout << "S3(" << n << ") = " << S3(n) << endl;
                break;
            case 5:
                cout << "S5(" << n << ") = " << S5(n) << endl;
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
        }
    }
    return 0;
}

