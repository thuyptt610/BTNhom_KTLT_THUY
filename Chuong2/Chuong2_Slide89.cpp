#include <stdio.h>

#define MAX_SIZE 100

// Hàm tính tổng các phần tử nằm trên đường chéo chính
int tongDuongCheoChinh(int matrix[][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += matrix[i][i];
    }
    return tong;
}
// 2. Hàm tính tổng các phần tử nằm trên đường chéo phụ
int tongDuongCheoPhu(int matrix[][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += matrix[i][n - 1 - i];
    }
    return tong;
}
// 3. Hàm tính tổng các phần tử nằm phía trên đường chéo chính
int tongPhiaTrenDuongCheoChinh(int matrix[][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tong += matrix[i][j];
        }
    }
    return tong;
}
//4. Hàm tính tổng các phần tử nằm phía trên đường chéo phụ
int tongPhiaTrenDuongCheoPhu(int matrix[][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            tong += matrix[i][j];
        }
    }
    return tong;
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n, choice;

    printf("Nhap kich thuoc ma tran vuong n: ");
    scanf_s("%d", &n);

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("matrix[%d][%d] = ", i, j);
            scanf_s("%d", &matrix[i][j]);
        }
    }
    do {
        printf("\n======================  MENU ======================\n");
        printf("1. Tong cac phan tu nam tren duong cheo chinh\n");
        printf("2. Tong cac phan tu nam tren duong cheo phu\n");
        printf("3. Tong cac phan tu nam phia tren duong cheo chinh\n");
        printf("4. Tong cac phan tu nam phia tren duong cheo phu\n");
        printf("5. Thoat\n");
        printf("\n===================================================\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &choice);

        // Xử lý lựa chọn bằng switch-case
        switch (choice) {
        case 1:
            printf("Tong cac phan tu nam tren duong cheo chinh: %d\n", tongDuongCheoChinh(matrix, n));
            break;
        case 2:
            printf("Tong cac phan tu nam tren duong cheo phu: %d\n", tongDuongCheoPhu(matrix, n));
            break;
        case 3:
            printf("Tong cac phan tu nam phia tren duong cheo chinh: %d\n", tongPhiaTrenDuongCheoChinh(matrix, n));
            break;
        case 4:
            printf("Tong cac phan tu nam phia tren duong cheo phu: %d\n", tongPhiaTrenDuongCheoPhu(matrix, n));
            break;
        case 5:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 5);

    return 0;
}
