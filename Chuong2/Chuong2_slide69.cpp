#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tu;
    int mau;
} PhanSo;

void rutGon(PhanSo* ps) {
    int a = ps->tu;
    int b = ps->mau;
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    ps->tu /= a;
    ps->mau /= a;
}

void nhapDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so %d (tu mau): ", i + 1);
        scanf_s("%d %d", &ds[i].tu, &ds[i].mau);
        rutGon(&ds[i]);
    }
}

void xuatDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", ds[i].tu, ds[i].mau);
    }
    printf("\n");
}

float giaTri(PhanSo ps) {
    return (float)ps.tu / ps.mau;
}

PhanSo timPhanSoMax(PhanSo ds[], int n) {
    PhanSo max = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTri(ds[i]) > giaTri(max)) {
            max = ds[i];
        }
    }
    return max;
}
PhanSo timPhanSoMin(PhanSo ds[], int n) {
    PhanSo min = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTri(ds[i]) < giaTri(min)) {
            min = ds[i];
        }
    }
    return min;
}

int main() {
    int n;
    PhanSo ds[50];
    int luaChon;

        printf("\n---------- MENU ----------\n");
        printf("1. Nhap danh sach phan so\n");
        printf("2. Xuat danh sach phan so\n");
        printf("3. Tim phan so lon nhat\n");
        printf("4. Tim phan so nho nhat\n");
        printf("5. Tinh tong cac phan so\n");
        printf("6. Tinh tich cac phan so\n");
        printf("7. Xuat nghich dao cac phan so\n");
        printf("8. Sap xep phan so tang dan\n");
        printf("9. Sap xep phan so giam dan\n");
        printf("0. Thoat\n");
        printf("----------------------------\n");
     do {
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &luaChon);

        switch (luaChon) {
        case 1:
            printf("Nhap so luong phan so (n <= 50): ");
            scanf_s("%d", &n);
            if (n > 50) {
                printf("So luong phan so khong vuot qua 50.\n");
            }
            else {
                nhapDanhSachPhanSo(ds, n);
            }
            break;

        case 2:
            printf("Danh sach phan so: ");
            xuatDanhSachPhanSo(ds, n);
            break;

        case 3:
            if (n > 0) {
                PhanSo max = timPhanSoMax(ds, n);
                printf("Phan so lon nhat: %d/%d\n", max.tu, max.mau);
            }
            else {
                printf("Danh sach rong.\n");
            }
            break;
        case 4:
            if (n > 0) {
                PhanSo min = timPhanSoMin(ds, n);
                printf("Phan so nho nhat: %d/%d\n", min.tu, min.mau);
            }
            else {
                printf("Danh sach rong.\n");
            }
            break;

        case 0:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le! Vui long chon lai.\n");
            break;
        }

        printf("Nhan Enter de tiep tuc...\n");
        getchar(); 
        getchar(); 

    } while (luaChon != 0);

    return 0;
}
