#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 

//1. Hàm đệ quy tính tổng S1(n) = 1 + 2 + 3 + ... + n
int S1(int n) {
    if (n == 1)
        return 1;
    return n + S1(n - 1);
}
// 2. Hàm đệ quy tính tổng S2(n) = 1 + 1/2 + 1/3 + ... + 1/n
double S2(int n) {
    if (n == 1)
        return 1.0;
    return 1.0 / n + S2(n - 1);
}
//3. Hàm đệ quy tính tổng S3(n) = 1*2 + 2*3 + 3*4 + ... + n*(n+1)
int S3(int n) {
    if (n == 1)
        return 1 * 2;
    return n * (n + 1) + S3(n - 1);
}


int main() {
    int choice, n;

    while (1) {
        system("cls");
        printf("\n========================== Menu =========================\n");
        printf("0. Thoat\n");
        printf("1. Tinh S1(n) = 1 + 2 + 3 + ... + n\n");
        printf("2. Tinh S2(n) = 1 + 1/2 + 1/3 + ... + 1/n\n");
        printf("3. Tinh S3(n) = 1*2 + 2*3 + 3*4 + ... + n*(n+1)\n");
        printf("\n=========================================================\n");
        printf("Nhap lua chon cua ban (0/1/2/3): ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("Thoat chuong trinh.\n");
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Lua chon khong hop le!\n");
            continue;
        }
        printf("Nhap gia tri cua n: ");
        scanf_s("%d", &n);
        switch (choice) {
        case 1:
            printf("Gia tri cua S1(%d) = %d\n", n, S1(n));
            break;
        case 2:
            printf("Gia tri cua S2(%d) = %lf\n", n, S2(n));
            break;
        case 3:
            printf("Gia tri cua S3(%d) = %d\n", n, S3(n));
            break;
        }
        printf("\nNhan Enter de tiep tuc...");
        getchar();
        getchar();
    }

    return 0;
}
