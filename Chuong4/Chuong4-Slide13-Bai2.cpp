#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 
// Hàm đệ quy tính giá trị của Un={(a,nếu n=1 và Un-1 + r,nếu n >1)
int U(int n, int a, int r) {
    if (n == 1) {
        return a;
    }
    else {
        return U(n - 1, a, r) + r;
    }
}
int main() {
    int n, a, r;
    printf("Nhap gia tri cua n: ");
    scanf_s("%d", &n);
    printf("Nhap gia tri cua a: ");
    scanf_s("%d", &a);
    printf("Nhap gia tri cua r: ");
    scanf_s("%d", &r);
    printf("Gia tri cua U(%d) = %d\n", n, U(n, a, r));

    return 0;
}
