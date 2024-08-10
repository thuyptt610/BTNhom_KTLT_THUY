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
// Hàm đệ quy tính S3(n) = 1/2 + 2/3 + ... + n/(n+1)
double S3_DQ(int n) {
    if (n == 1) return 1.0 / 2;
    return (double)n / (n + 1) + S3_DQ(n - 1);
}

// Hàm khử đệ quy tính S3(n) = 1/2 + 2/3 + ... + n/(n+1)
double S3_khuDeQuy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (double)i / (i + 1);
    }
    return sum;
}
//4. Hàm đệ quy tính S4(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1)
double S4_DQ(int n, int current) {
    if (current > n) return 0.0;
    return 1.0 / (2 * current + 1) + S4_DQ(n, current + 1);
}

// Hàm khử đệ quy tính S4(n) = 1 + 1/3 + 1/5 + ... + 1/(2n+1)
double S4_khuDeQuy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (2 * i + 1);
    }
    return sum;
}
//5. Hàm đệ quy tính S5(n) = 1*2 + 2*3 + 3*4 + ... + n*(n+1)
int S5_DQ(int n) {
    if (n == 1) return 1 * 2;
    return n * (n + 1) + S5_DQ(n - 1);
}

// Hàm khử đệ quy tính S5(n) = 1*2 + 2*3 + 3*4 + ... + n*(n+1)
int S5_khuDeQuy(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * (i + 1);
    }
    return sum;
}
//6. Hàm đệ quy tính S6(n) = 1/(1*2*3) + 1/(2*3*4) + ... + 1/(n*(n+1)*(n+2))
double S6_DQ(int n) {
    if (n == 1) return 1.0 / (1 * 2 * 3);
    return 1.0 / (n * (n + 1) * (n + 2)) + S6_DQ(n - 1);
}

// Hàm khử đệ quy tính S6(n) = 1/(1*2*3) + 1/(2*3*4) + ... + 1/(n*(n+1)*(n+2))
double S6_khuDeQuy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += 1.0 / (i * (i + 1) * (i + 2));
    }
    return sum;
}
//7. Hàm đệ quy tính S7(n) = 1^2 + 2^2 + ... + n^2
int S7_DQ(int n) {
    if (n == 1) return 1 * 1;
    return n * n + S7_DQ(n - 1);
}

// Hàm khử đệ quy tính S7(n) = 1^2 + 2^2 + ... + n^2
int S7_khuDeQuy(int n) {
    return (n * (n + 1) * (2 * n + 1)) / 6;
}
//8.  Hàm đệ quy tính S8(n) = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+n)
int S8_DQ(int n, int current) {
    if (current > n) return 0;
    return (current * (current + 1)) / 2 + S8_DQ(n, current + 1);
}

// Hàm khử đệ quy tính S8(n) = 1 + (1+2) + (1+2+3) + ... + (1+2+3+...+n)
int S8_khuDeQuy(int n) {
    return (n * (n + 1) * (n + 2)) / 6;
}
// Hàm tính giai thừa của số nguyên dương
int factorial(int x) {
    if (x == 0 || x == 1) return 1;
    return x * factorial(x - 1);
}

//9. Hàm đệ quy tính S9(n) = -1 + 2/2! + 3/3! - 4/4! + ... + (-1)^n * (2*n-1) / (2*n)!
double S9_DQ(int n) {
    if (n == 1) return -1;
    double term = (double)(2 * n - 1) / factorial(2 * n);
    if (n % 2 == 0) term = -term; // Đổi dấu cho các số hạng chẵn
    return term + S9_DQ(n - 1);
}

// Hàm khử đệ quy tính S9(n) = -1 + 2/2! + 3/3! - 4/4! + ... + (-1)^n * (2*n-1) / (2*n)!
double S9_khuDeQuy(int n) {
    double sum = -1.0;
    for (int i = 2; i <= n; i++) {
        double term = (double)(2 * i - 1) / factorial(2 * i);
        if (i % 2 == 0) term = -term; // Đổi dấu cho các số hạng chẵn
        sum += term;
    }
    return sum;
}
//10. Hàm đệ quy tính S10(n) = 1*2!/2 + sqrt(3) + 2*3!/3 + sqrt(4) + ... + n*(n+1)!/(n+1) + sqrt(n+2)
double S10_DQ(int n, int current) {
    if (current > n) return 0.0;
    double term = (current * factorial(current + 1)) / (current + 1);
    return term + sqrt(current + 2) + S10_DQ(n, current + 1);
}

// Hàm khử đệ quy tính S10(n) = 1*2!/2 + sqrt(3) + 2*3!/3 + sqrt(4) + ... + n*(n+1)!/(n+1) + sqrt(n+2)
double S10_khuDeQuy(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += (i * factorial(i + 1)) / (i + 1);
        sum += sqrt(i + 2);
    }
    return sum;
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
        case 3:
            printf("Gia tri cua S3(%d) = %lf (de quy) va (khu de quy) = %lf \n", n, S3_DQ(n), S3_khuDeQuy(n));
            break;
        case 4:
            printf("Gia tri cua S4(%d) = %lf (de quy) va (khu de quy) = %lf \n", n, S4_DQ(n, 1), S4_khuDeQuy(n));
            break;
        case 5:
            printf("Gia tri cua S5(%d) = %d (de quy) va (khu de quy)= %d \n", n, S5_DQ(n), S5_khuDeQuy(n));
            break;
        case 6:
            printf("Gia tri cua S6(%d) = %lf (de quy) va (khu de quy) = %lf \n", n, S6_DQ(n), S6_khuDeQuy(n));
            break;
        case 7:
            printf("Gia tri cua S7(%d) = %d (de quy) va (khu de quy)= %d \n", n, S7_DQ(n), S7_khuDeQuy(n));
            break;
        case 8:
            printf("Gia tri cua S8(%d) = %d (de quy) va (khu de quy) = %d \n", n, S8_DQ(n, 1), S8_khuDeQuy(n));
            break;
        case 9:
            printf("Gia tri cua S9(%d) = %lf (de quy) va (khu de quy)= %lf \n", n, S9_DQ(n), S9_khuDeQuy(n));
            break;
        case 10:
            printf("Gia tri cua S10(%d) = %lf (de quy) va (khu de quy)= %lf \n", n, S10_DQ(n, 1), S10_khuDeQuy(n));
            break;
        }
        printf("\nNhan Enter de tiep tuc...");
        getchar();
        getchar();
    }

    return 0;
}
