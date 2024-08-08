#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void nhapVaoMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri cua phan tu %d: ", i);
        scanf_s("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    printf("\nGia tri cac phan tu trong mang\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d cua mang la: %d\n", i, a[i]);
    }
}

int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        max = (max > a[i]) ? max : a[i];
    }
    return max;
}

int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        min = (min < a[i]) ? min : a[i];
    }
    return min;
}

void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Nhap mang/ xuat mang a\n");
    printf("2. Tim gia tri max/min\n");
 
   
}
int main() {
    menu();
    int n, choice, x;
    int a[50];
    srand(time(0)); 

    do {

        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);
       
        switch (choice) {
       
        case 1:
            printf("Nhap n so nguyen: ");
            scanf_s("%d", &n);
            if (n > 50 || n <= 0) {
                printf("So luong phan tu khong hop le!\n");
                return 1;
            }
            nhapVaoMang(a, n);
            xuatMang(a, n);
            break;
        case 2:
            printf("Gia tri max: %d\n", timMax(a, n));
            printf("Gia tri min: %d\n", timMin(a, n));
            break;
        case 12:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 12);

    return 0;
}
