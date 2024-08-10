#include <stdio.h>
#include <math.h> 
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

// 1. Hàm đệ quy tính S1(n) = 1 + 2 + 3 + ... + n
int S1_DQ(int n) {
    if (n == 1) return 1;
    return n + S1_DQ(n - 1);
}

// Hàm khử đệ quy tính S1(n) = 1 + 2 + 3 + ... + n
int S1_khuDeQuy(int n) {
    return (n * (n + 1)) / 2;
}
//2. Hàm đệ quy tính S2(n) = CanBac2(2 + CanBac2(2 + ... + CanBac2(2)))
double S2_DQ(int n) {
    if (n == 1) return sqrt(2);
    return sqrt(2 + S2_DQ(n - 1));
}

// Hàm khử đệ quy tính S2(n) = CanBac2(2 + CanBac2(2 + ... + CanBac2(2)))
double S2_khuDeQuy(int n) {
    double result = 2.0;
    for (int i = 1; i < n; i++) {
        result = sqrt(2 + result);
    }
    return result;
}

int main() {
    int choice, n;
    while (1) {
        system("cls");
        printf("\n==================================================== Menu =====================================================\n");
        printf("0. Thoat\n");
        printf("1. Tinh S1(n) = 1 + 2 + 3 + ... + n\n");
        printf("2. Tinh S2(n) = CanBac2(2+CanBac2(2+….+CanBac2(2 + CanBac2(2))))\n");
        printf("3. Tinh S3(n) = 1/2 + 2/3 + ... + n/(n+1)\n");
        printf("4. Tinh S4(n) = 1 + 1/3 + 1/5 +... + 1/(2n+1)\n");
        printf("5. Tinh S5(n) = 1*2 + 2*3 + 3*4 + 4*5 + ... + n*(n+1)\n");
        printf("6. Tinh S6(n) = 1/(1*2*3) + 1/(2*3*4) + ... + 1/(n*(n+1)*(n+2))\n");
        printf("7. Tinh S7(n) = 1^2 + 2^2 + ... + n^2\n");
        printf("8. Tinh S8(n) = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+n)\n");
        printf("9. Tinh S9(n) = -1 + 2/2! + 3/3! - 4/4! + ... + (-1)^n * (2*n-1) / (2*n)!\n");
        printf("10. Tinh S10(n) = 1*2!/2 + sqrt(3) + 2*3!/3 + sqrt(4) + ... + n*(n+1)!/(n+1) + sqrt(n+2)\n");
        printf("11. Tinh S11(n) = 1 + sqrt(1+2)/2+sqrt(3!) + 2+sqrt(2+3)/3+sqrt(4!) + ... + n + sqrt(n+n+1)/(n+1) + sqrt((n+2)!)\n");
        printf("\n================================================================================================================\n");
        printf("Nhap lua chon cua ban (0-11): ");
        scanf_s("%d", &choice);

        if (choice == 0) {
            printf("Thoat chuong trinh.\n");
            break;
        }

        if (choice < 1 || choice > 11) {
            printf("Lua chon khong hop le!\n");
            continue;
        }

        printf("Nhap gia tri cua n: ");
        scanf_s("%d", &n);

        switch (choice) {
        case 1:
            printf("Gia tri cua S1(%d) = %d (de quy) va (khu de quy) = %d \n", n, S1_DQ(n), S1_khuDeQuy(n));
            break;
        case 2:
            printf("Gia tri cua S2(%d) = %lf (de quy) va (khu de quy) = %lf\n", n, S2_DQ(n), S2_khuDeQuy(n));
            break;
        }
        printf("\nNhan Enter de tiep tuc...");
        getchar();
        getchar();
    }

    return 0;
}
