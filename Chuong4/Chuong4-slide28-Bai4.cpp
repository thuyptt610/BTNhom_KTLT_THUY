#include <stdio.h>

// Ham tinh phan tu thu n cua phap cong
int find_nth_term(int a, int r, int n);

int main() {
    int a, r, n;

    printf("Nhap hang dau (a): ");
    scanf_s("%d", &a);
    printf("Nhap cong sai (r): ");
    scanf_s("%d", &r);
    do {
        printf("Nhap chi so phan tu(n): ");
        scanf_s("%d", &n);
        if (n < 0) {
            printf("Chi so phan tu thu n phai khong am.\n");

        }
    } while (n < 0);

    int result = find_nth_term(a, r, n);
    if (result != -1) {
        printf("Gia tri phan tu thu %d la: %d\n", n, result);
    }

    return 0;
}

int find_nth_term(int a, int r, int n) {

    if (n == 0) {
        return a;
    }
    else {
        return find_nth_term(a, r, n - 1) + r;
    }
}
