#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void xuatMang(int a[20], int n) {
    printf("\nGia tri cac phan tu trong mang\n");
    for (int i = 0; i < n; i++) {
        printf(" %d\t", a[i]);
    }
}

void taoMangNgauNhien(int a[20], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100; // sinh so ngau nhien tu 0 den 99
    }
}
// Kiem tra so nguyen to
int laNguyenTo(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}
// Dem so nguyen to trong mang
int demNguyenTo(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laNguyenTo(arr[i])) {
            count++;
        }
    }
    return count;
}

//2. Kiem tra tat ca cac chu so la so le
int tatCaLaLe(int num) {
    num = abs(num);
    while (num > 0) {
        int digit = num % 10;
        if (digit % 2 == 0) return 0;
        num /= 10;
    }
    return 1;
}
int main() {
    int arr[20]; // Mang vi du
    int n = 10;
    taoMangNgauNhien(arr, n);
    xuatMang(arr, n);
    int choice;
    printf("\nMenu:\n");
    printf("1. Dem so phan tu la so nguyen to trong mang\n");
    printf("2. Xuat cac phan tu co tat ca chu so la so le\n");
    printf("3. Tim vi tri so lon nhat cuoi cung cua mang\n");
    printf("4. Kiem tra tat ca cac phan tu trong mang deu la so chan\n");
    printf("5. Kiem tra mang co phai la day so chan le xen ke\n");
    printf("0. Thoat\n");
    do {
        printf("Lua chon cua ban: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("So phan tu la so nguyen to trong mang: %d\n", demNguyenTo(arr, n));
            break;
       
        case 2:
            printf("Cac phan tu co tat ca chu so la so le: ");
            for (int i = 0; i < n; i++) {
                if (tatCaLaLe(arr[i])) {
                    printf("%d ", arr[i]);
                }
            }
            printf("\n");
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}
