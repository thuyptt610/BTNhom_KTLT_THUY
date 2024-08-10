#include <stdio.h>

// Hàm de quy tinh gt cua U(n)
int U(int n);

int main() {
    int n;
    do {

        printf("Nhap so nguyen duong n: ");
        scanf_s("%d", &n);


        if (n <= 0) {
            printf("n phai la so nguyen duong!\n");

        }
    } while (n <= 0);

    int result = U(n);
    printf("Gia tri cua U(%d) la: %d\n", n, result);

    return 0;
}

int U(int n) {

    if (n < 6) {
        return n;
    }

    else {
        return U(n - 5) + U(n - 4) + U(n - 3) + U(n - 2) + U(n - 1);
    }
}