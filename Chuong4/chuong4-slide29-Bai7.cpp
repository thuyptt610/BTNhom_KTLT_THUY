#include <stdio.h>
#include <stdlib.h> 


int A1(int n);
int A2(int n);

int main() {
    int n;

    do {
        printf("Nhap so nguyen duong n: ");
        scanf_s("%d", &n);

        if (n < 0) {
            printf("n phai la so nguyen duong!\n");
        }
    } while (n < 0);

    // Kq cho ct 1
    int result1 = A1(n);
    printf("Gia tri cua A(%d) theo cong thuc 1 la: %d\n", n, result1);

    // Kq cong thuc 2
    int result2 = A2(n);
    printf("Gia tri cua A(%d) theo cong thuc 2 la: %d\n", n, result2);

    return 0;
}

// Hàm de quy tinh gt cuaa A(n) theo cong thuc 1
int A1(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return -1;

    return 2 * A1(n - 1) - 3 * A1(n - 2) - A1(n - 3);
}

// Hàm tinh gt của A(n) theo ct 2 bang luu tru mang
int A2(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

   
    int* A = (int*)malloc((n + 1) * sizeof(int));
    if (A == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1); 
    }

    A[1] = 1;
    A[2] = 2;
    A[3] = 3;

   
    for (int i = 4; i <= n; i++) {
        A[i] = 2 * A[i - 1] + A[i - 2] - 3 * A[i - 3];
    }

    int result = A[n];
    free(A); 
    return result;
}
