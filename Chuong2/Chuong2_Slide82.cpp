#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

#define MAX_ROW 100
#define MAX_COL 100


// Bài 1: Liệt kê các cột có tổng nhỏ nhất trong ma trận
void lietKeCotTongNhoNhat(int matrix[][MAX_COL], int m, int n) {
	int tongCot[MAX_COL] = { 0 };
	int minTong = INT_MAX;

	for (int j = 0; j < n; j++) {
		int tong = 0;
		for (int i = 0; i < m; i++) {
			tong += matrix[i][j];
		}
		tongCot[j] = tong;
		if (tong < minTong) {
			minTong = tong;
		}
	}

	printf("Cac cot co tong nho nhat:\n");
	for (int j = 0; j < n; j++) {
		if (tongCot[j] == minTong) {
			printf("Cot %d\n", j);
		}
	}
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
		printf("1. Liet ke cac cot co tong nho nhat\n");
		printf("2. Liet ke cac dong co nhieu so hoan thien nhat\n");
		printf("3. Liet ke chi so cac dong chua toan gia tri chan\n");
		printf("4. Tim gia tri xuat hien nhieu nhat\n");
		printf("5. Tim so nguyen to nho nhat\n");
		printf("6. Tim phan tu lon (nho) nhat trong dong thu k\n");
		printf("7. Tim phan tu lon (nho) nhat trong cot thu k\n");
		printf("8. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &luaChon);

		switch (luaChon) {
		case 1:
s			lietKeCotTongNhoNhat(matrix, m, n);
			break;

		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (luaChon != 8);

	return 0;
}
