#include <stdio.h>

// Tinh day A(n) : A1 = 1, An = n(A1 + A2 + .. + A(n - 1))

int sumOfA(int n);
int A(int n);

int main() {
    int n;

    do {
        printf("Nhap gia tri n: ");
        scanf_s("%d", &n);

        if (n < 1) {
            printf("n phai la so nguyen duong!\n");

        }
    } while (n < 1);

    int result = A(n);
    printf("A(%d) = %d\n", n, result);

    return 0;
}


// Ham de quy tinh tong dãy A tu A(1) den A(n-1)
int sumOfA(int n) {
    if (n == 1) return 1;
    return sumOfA(n - 1) + A(n - 1);
}

// Hàm de quy tinh  A(n)
int A(int n) {
    if (n == 1) return 1;
    return n * sumOfA(n);
}