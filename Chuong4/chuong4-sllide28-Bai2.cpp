#include <stdio.h>

// ham de quy tinh luy thua m^n
int powerRecursive(int m, int n);

int main() {
    int m, n;

    do {
        printf("Nhap so nguyen duong n: ");
        scanf_s("%d", &n);

        if (n <= 0) {
            printf("n phai la so nguyen duong!\n");
        }

    } while (n <= 0);

    printf("Nhap vao so nguyen m: ");
    scanf_s("%d", &m);

    

    int result = powerRecursive(m, n);

   
    printf("%d mu %d = %d\n", m, n, result);

    return 0;
}

int powerRecursive(int m, int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return m * powerRecursive(m, n - 1);
    }
}