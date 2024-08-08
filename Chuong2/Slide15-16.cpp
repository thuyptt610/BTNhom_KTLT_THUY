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

void demChanLe(int a[], int n) {
    int chan = 0, le = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            chan++;
        else
            le++;
    }
    printf("\nSo phan tu chan la: %d\n", chan);
    printf("So phan tu le la: %d\n", le);
}
// tim kiem tuyen tinh
int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i; // Tra ve vi tri dau tien tim thay
        }
    }
    return -1; // Khong tim thay
}
// Tim kiem nhi phan
int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid; // Tra ve vi tri tim thay
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Khong tim thay
}
// dem so lan phan tu x xuat hien tren a
void demsolanXxuathien(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }

    printf("So lan xuat hien cua %d trong mang la: %d\n", x, count);
}
// dem tren a co bao nhieu phan tu lón hon x
void Cau6(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x)
            count++;
    }
    printf("So phan tu lon hon %d la %d\n", x, count);
}
// 7. Tong phan tu cua mang a
void Tongmang(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    printf("Tong mang la: %d\n", sum);
}

int kiemTraNguyenTo(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
// xuat cac so nguyen to
void Cau8(int a[], int n) {
    printf("\nSo nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (kiemTraNguyenTo(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}
int laSoHoanThien(int num) {
    int sum = 0;
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
   return sum == num;
}
// Hàm xu?t các s? hoàn thi?n trong m?ng
void isSoHoanThien(int a[], int n) {
    printf("Cac so hoan thien trong mang la: ");
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (laSoHoanThien(a[i])) {
            printf("%d ", a[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong co so hoan thien nao trong mang.");
    }
     printf("\n");
}
//xuat cac phan tu chan le trong mang a
void xuatvitriChanLe(int a[], int n) {
    //chan
    printf("Cac phan tu o vi tri chan trong mang la: ");
    for (int i = 0; i < n; i += 2) { 
        printf("%d ", a[i]);
    }
    printf("\n");

    // Xu?t các ph?n t? ? v? trí l?
    printf("Cac phan tu o vi tri le trong mang la: ");
    for (int i = 1; i < n; i += 2) { 
        printf("%d ", a[i]);
    }
    printf("\n");
}
// ghep mang
void ghepMang(int b[], int m, int c[], int n, int a[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (b[i] < c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i < m) {
        a[k++] = b[i++];
    }
    while (j < n) {
        a[k++] = c[j++];
    }
}
void menu() {
    printf("\n========== Menu=============\n");
    printf("1. Nhap mang/ xuat mang a\n");
    printf("2. Tim gia tri max/min\n");
    printf("3. Dem so luong chan/le\n");
    printf("4(4.1). Tim kiem tuyen tinh\n");
    printf("5(4.2). Tim kiem nhi phan\n");
    printf("6.(5). Dem tren a co bao nhieu phan tu x\n");
    printf("7.(6). Dem so phan tu lon hon x\n");
    printf("8.(7). Tinh tong cac phan tu cua a\n");
    printf("9.(8). Xuat cac so nguyen to trong a\n");
    printf("10.(9). Xuat cac so hoan thien trong a\n");
    printf("11.(10). Xuat cac vi tri chan le\n");
    printf("12.(12). Ghep mang\n");
    printf("5========================================\n");
}
int main() {
    menu();
    int n, choice, x;
    int a[50];
    srand(time(0)); 
    int viTriTuyenTinh;
    int viTriNhiPhan;
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
        case 3:
            demChanLe(a, n);
            break;
        case 4:
            printf("Nhap gia tri x de tim trong mang: ");
            scanf_s("%d", &x);
            viTriTuyenTinh = timKiemTuyenTinh(a, n, x);
            if (viTriTuyenTinh != -1) {
                printf("Gia tri %d xuat hien tai vi tri %d trong mang.\n", x, viTriTuyenTinh);
            }
            else {
                printf("Gia tri %d khong co trong mang.\n", x);
            }
            break;
        case 5:
            printf("Nhap gia tri x de tim trong mang: ");
            scanf_s("%d", &x);
            viTriNhiPhan = timKiemNhiPhan(a, n, x);
            if (viTriNhiPhan != -1) {
                printf("Gia tri %d xuat hien tai vi tri %d trong mang.\n", x, viTriNhiPhan);
            }
            else {
                printf("Gia tri %d khong co trong mang.\n", x);
            }
            break;
        case 6:
            printf("Nhap phan tu x can dem: ");
            scanf_s("%d", &x);
            demsolanXxuathien(a, n, x);
            break;
        case 7:
            printf("Nhap vao gia tri x: ");
            scanf_s("%d", &x);
            Cau6(a, n, x);
            break;
        case 8:
            Tongmang(a, n);
            break;
        case 9:
            Cau8(a, n);
            break;
        case 10:
            isSoHoanThien(a, n);
            break;
        case 11:
            xuatvitriChanLe(a, n);
            break;
        case 12: {
            int m, p;
            int b[50], c[50];
            printf("Nhap so luong phan tu cua mang b: ");
            scanf_s("%d", &m);
            printf("Nhap cac phan tu cua mang b (tang dan):\n");
            for (int i = 0; i < m; i++) {
                scanf_s("%d", &b[i]);
            }
            printf("Nhap so luong phan tu cua mang c: ");
            scanf_s("%d", &p);
            printf("Nhap cac phan tu cua mang c (tang dan):\n");
            for (int i = 0; i < p; i++) {
                scanf_s("%d", &c[i]);
            }
            ghepMang(b, m, c, p, a);
            printf("Mang a sau khi ghep la:\n");
            xuatMang(a, m + p);
            break;
        }
        case 13:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 12);

    return 0;
}
