#include <stdio.h>


// Ham tinh phan tu thu n cua phap nhan
int geometricSequence(int a, int q, int n);
int main() {
    int a, q, n;

    printf("Nhap hang dau (a): ");
    scanf_s("%d", &a);
    printf("Nhap cong boi (q): ");
    scanf_s("%d", &q);
    printf("Nhap chi so phan tu(n): ");
    scanf_s("%d", &n);

    int result = geometricSequence(a, q, n);
    printf("Gia tri phan tu thu %d la: %d\n", n, result);

    return 0;
}

int geometricSequence(int a, int q, int n) {
    if (n == 0) {
        return a;
    }
    else {
        return q * geometricSequence(a, q, n - 1);
    }
}
