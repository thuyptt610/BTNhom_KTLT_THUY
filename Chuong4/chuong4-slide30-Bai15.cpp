#include <stdio.h>

//với mỗi n>=1, Y(n) được tính nhu sau Y1=1, Y2=2, Y3=3, Yn=Y(n-1)+2Y(n-2)+ 3Y(n-3) nếu n>=4 dùn 2 cách khử đệ quy và đệ quy 


// Ham de quy tinh gt Y(n)
int Y_DQ(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;
    return Y_DQ(n - 1) + 2 * Y_DQ(n - 2) + 3 * Y_DQ(n - 3);
}

// Ham khu de quy Y(n)
int Y_KDQ(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 3;

    int y1 = 1, y2 = 2, y3 = 3;
    int current;

    for (int i = 4; i <= n; ++i) {
        current = y1 + 2 * y2 + 3 * y3;
        y1 = y2;
        y2 = y3;
        y3 = current;
    }

    return current;
}

int main() {
    int choice, n, result;

    do {
       
        printf("============= Chuong trinh tinh Y(n) =============\n");
        printf("1. Tinh Y(n) theo cach de quy\n");
        printf("2. Tinh Y(n) theo cach khu de quy\n");
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
                result = Y_DQ(n);
                printf("Y(%d) theo cach de quy = %d\n", n, result);
            }
            break;

        case 2:
            printf("Nhap gia tri n (n >= 1): ");
            scanf_s("%d", &n);
            if (n < 1) {
                printf("Gia tri n phai >= 1!\n");
            }
            else {
                result = Y_KDQ(n);
                printf("Y(%d) theo cach khu de quy = %d\n", n, result);
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
