#include <stdio.h>

//với mỗi n>=1, X(n) được tính nhu sau X1=1, X2=1, Xn=X(n-1)+(n-1)X(n-2) nếu n>=3 dùn 2 cách khử đệ quy và đệ quy 

// Hàm tinh de quy X(n)
int X_DQ(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    return X_DQ(n - 1) + (n - 1) * X_DQ(n - 2);
}

// Hàm tinh khu de quy X(n)
int X_KDQ(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;

    int X1 = 1, X2 = 1, Xn;
    for (int i = 3; i <= n; ++i) {
        Xn = X1 + (i - 1) * X2;
        X1 = X2;
        X2 = Xn;
    }

    return Xn;
}

int main() {
    int choice, n, result;

    do {
    
        printf("============= Chuong trinh tinh X(n) =============\n");
        printf("1. Tinh X(n) theo cach de quy\n");
        printf("2. Tinh X(n) theo cach khu de quy\n");
        printf("3. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

      
        switch (choice) {
        case 1:
            printf("Nhap gia tri n (n >= 1): ");
            scanf_s("%d", &n);
            if (n < 1) {
                printf("Gia tri n phai >= 1!\n");
            }
            else {
                result = X_DQ(n);
                printf("X(%d) theo cach de quy = %d\n", n, result);
            }
            break;

        case 2:
            printf("Nhap gia tri n (n >= 1): ");
            scanf_s("%d", &n);
            if (n < 1) {
                printf("Gia tri n phai >= 1!\n");
            }
            else {
                result = X_KDQ(n);
                printf("X(%d) theo cach khu de quy = %d\n", n, result);
            }
            break;

        case 3:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le! Vui long chon lai.\n");
        }
    } while (choice != 3);

    return 0;
}
