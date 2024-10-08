﻿#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_ROW 100
#define MAX_COL 100



// Hàm kiểm tra chữ số đầu là chữ số lẻ
bool chuSoDauLe(int num) {
	while (num >= 10) {
		num /= 10;
	}
	return num % 2 != 0;
}

//1. Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongChuSoDauLe(int matrix[][MAX_COL], int m, int n) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (chuSoDauLe(matrix[i][j])) {
				tong += matrix[i][j];
			}
		}
	}
	return tong;
}
// Hàm kiểm tra số hoàn thiện
bool laSoHoanThien(int num) {
	if (num <= 0) return false;
	int tong = 0;
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0) {
			tong += i;
		}
	}
	return tong == num;
}

// 2.Hàm liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int matrix[][MAX_COL], int m, int n) {
	bool timThay = false;
	printf("Cac so hoan thien trong ma tran:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laSoHoanThien(matrix[i][j])) {
				printf("%d ", matrix[i][j]);
				timThay = true;
			}
		}
	}
	if (!timThay) {
		printf("Khong co so hoan thien nao.\n");
	}
	printf("\n");
}
// 3.Hàm tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int tongLonHonTriTuyetDoiSau(int matrix[][MAX_COL], int m, int n) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (matrix[i][j] > abs(matrix[i][j + 1])) {
				tong += matrix[i][j];
			}
		}
	}
	return tong;
}

//4. Hàm tính tổng giá trị trên dòng k của ma trận
int tongDauDong(int matrix[][MAX_COL], int m, int n, int k) {
	int tong = 0;
	if (k >= 0 && k < m) {
		for (int j = 0; j < n; j++) {
			tong += matrix[k][j];
		}
	}
	else {
		printf("Dong %d khong ton tai.\n", k);
	}
	return tong;
}

// 5.Hàm tính tổng các giá trị nằm trên biên của ma trận
int tongBien(int matrix[][MAX_COL], int m, int n) {
	int tong = 0;
	for (int i = 0; i < m; i++) {
		tong += matrix[i][0] + matrix[i][n - 1]; // Cột biên trái và phải
	}
	for (int j = 1; j < n - 1; j++) {
		tong += matrix[0][j] + matrix[m - 1][j]; // Hàng biên trên và dưới
	}
	return tong;
}
//6. Hàm đếm tần suất xuất hiện của 1 giá trị x trong ma trận
int demGiaTriXuatHien(int matrix[][MAX_COL], int m, int n, int x) {
	int dem = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == x) {
				dem++;
			}
		}
	}
	return dem;
}

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int num) {
	if (num <= 1) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	for (int i = 3; i <= sqrt((float)num); i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}

//7. Hàm đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void demSoLuongPhanTu(int matrix[][MAX_COL], int m, int n) {
	int soChan = 0, soLe = 0, soAm = 0, soDuong = 0, soNguyenTo = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] % 2 == 0) {
				soChan++;
			}
			else {
				soLe++;
			}
			if (matrix[i][j] < 0) {
				soAm++;
			}
			else if (matrix[i][j] > 0) {
				soDuong++;
			}
			if (laSoNguyenTo(matrix[i][j])) {
				soNguyenTo++;
			}
		}
	}

	printf("So luong so chan: %d\n", soChan);
	printf("So luong so le: %d\n", soLe);
	printf("So luong so am: %d\n", soAm);
	printf("So luong so duong: %d\n", soDuong);
	printf("So luong so nguyen to: %d\n", soNguyenTo);
}

int main() {
	int matrix[MAX_ROW][MAX_COL];
	int m, n;
	int luaChon;

	// Nhập kích thước ma trận
	printf("Nhap so hang (m) va so cot (n): ");
	scanf_s("%d %d", &m, &n);

	// Nhập các phần tử của ma trận
	printf("Nhap cac phan tu cua ma tran:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("matrix[%d][%d] = ", i, j);
			scanf_s("%d", &matrix[i][j]);
		}
	}

	do {
		// Hiển thị menu
		printf("\n----------Menu----------\n");
		printf("1. Tinh tong cac phan tu co chu so dau la chu so le\n");
		printf("2. Liet ke cac so hoan thien trong ma tran\n");
		printf("3. Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no\n");
		printf("4. Tinh tong gia tri tren dong k cua ma tran\n");
		printf("5. Tinh tong cac gia tri nam tren bien cua ma tran\n");
		printf("6. Dem tan suat xuat hien cua 1 gia tri x trong ma tran\n");
		printf("7. Dem so luong cac phan tu la so chan, so le, so am, so duong, so nguyen to\n");
		printf("8. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &luaChon);

		switch (luaChon) {
		case 1:
			printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLe(matrix, m, n));
			break;
		case 2:
			lietKeSoHoanThien(matrix, m, n);
			break;
		case 3:
			printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", tongLonHonTriTuyetDoiSau(matrix, m, n));
			break;

		case 4:
		{
			int k;
			printf("Nhap dong k de tinh tong: ");
			scanf_s("%d", &k);
			printf("Tong gia tri tren dong %d: %d\n", k, tongDauDong(matrix, m, n, k));
		}
		break;
		case 5:
			printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", tongBien(matrix, m, n));
			break;
		case 6:
		{
			int x;
			printf("Nhap gia tri x de dem so lan xuat hien: ");
			scanf_s("%d", &x);
			printf("Gia tri %d xuat hien %d lan.\n", x, demGiaTriXuatHien(matrix, m, n, x));
		}
		break;
		case 7:
			demSoLuongPhanTu(matrix, m, n);
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (luaChon != 8);

	return 0;
}
