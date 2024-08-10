#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

// Hàm đệ quy tính giá trị phần tử thứ n của cấp số nhân  Un={(a,nếu n=1 và q*Un-1,nếu n >1)
double U_n(int n, double a, double q) {
    if (n == 1) {
        return a;
    }
    else {
        return q * U_n(n - 1, a, q);
    }
}
int main() {
    int n;
    double a, q;
    printf("Nhap gia tri cua n: ");
    scanf_s("%d", &n);
    printf("Nhap gia tri cua a: ");
    scanf_s("%lf", &a);
    printf("Nhap gia tri cua q: ");
    scanf_s("%lf", &q);
    printf("Gia tri cua phan tu thu %d cua cap so nhan la: %.2lf\n", n, U_n(n, a, q));

    return 0;
}
