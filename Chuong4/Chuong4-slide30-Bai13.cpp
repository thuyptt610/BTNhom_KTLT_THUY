#include <stdio.h>

// Tính: hàm tính số hạng n của 2 dãy sau:
//  X0 = 1, y0 = 0;
//  Xn = X(n - 1) + Y(n - 1), v?i n > 0;
//  Yn = 3X(n - 1) + 2Y(n - 1), v?i n > n

int X(int n);
int Y(int n);

int main() {
    int n;
    do {

        printf("Nhap gia tri n: ");
        scanf_s("%d", &n);

        if (n < 0) {
            printf("n phai la so nguyen duong!\n");

        }
    } while (n<0);
    
    int x_n = X(n);
    int y_n = Y(n);

    printf("X(%d) = %d\n", n, x_n);
    printf("Y(%d) = %d\n", n, y_n);

    return 0;
}

// Hàm de quy tinh X(n)
int X(int n) {
    if (n == 0) return 1; 
    return X(n - 1) + Y(n - 1);
}

// Ham de quy tinh  Y(n)
int Y(int n) {
    if (n == 0) return 0; 
    return 3 * X(n - 1) + 2 * Y(n - 1);
}