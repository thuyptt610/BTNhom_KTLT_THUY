#include <stdio.h>

// Hàm đệ quy  tính UCLN của a và b theo phương pháp Euclid 
int gcdRecursive(int a, int b);

int main() {
    int a, b;

    do {
        printf("Nhap so nguyen duong a: ");
        scanf_s("%d", &a);

        if (a <= 0) {
            printf("a phai la so nguyen duong!\n");
        }
    } while (a <= 0);

    do {
        printf("Nhap so nguyen duong b: ");
        scanf_s("%d", &b);

        if (b <= 0) {
            printf("b phai la so nguyen duong!\n");
        }
    } while (b <= 0);

    int result = gcdRecursive(a, b);

    printf("UCLN cua %d va %d la %d\n", a, b, result);

    return 0;
}

int gcdRecursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    else if (a > b) {
        return gcdRecursive(b, a - b);
    }
    else {
        return gcdRecursive(a, b - a);
    }
}

