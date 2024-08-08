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


void menu() {
    printf("\n--- Menu ---\n");
    printf("1. Nhap mang/ xuat mang a\n");
 
   
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
