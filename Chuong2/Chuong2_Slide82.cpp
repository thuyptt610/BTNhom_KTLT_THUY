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

// Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất trong ma trận
void lietKeDongNhieuSoHoanThienNhat(int matrix[][MAX_COL], int m, int n) {
	int soHoanThien[MAX_ROW] = { 0 };
	int maxSoHoanThien = 0;

	for (int i = 0; i < m; i++) {
		int dem = 0;
		for (int j = 0; j < n; j++) {
			if (laSoHoanThien(matrix[i][j])) {
				dem++;
			}
		}
		soHoanThien[i] = dem;
		if (dem > maxSoHoanThien) {
			maxSoHoanThien = dem;
		}
	}

	printf("Cac dong co nhieu so hoan thien nhat:\n");
	for (int i = 0; i < m; i++) {
		if (soHoanThien[i] == maxSoHoanThien) {
			printf("Dong %d\n", i);
		}
	}
}

// Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void lietKeDongToanGiaTriChan(int matrix[][MAX_COL], int m, int n) {
	printf("Cac dong chua toan gia tri chan:\n");
	for (int i = 0; i < m; i++) {
		bool toanChan = true;
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] % 2 != 0) {
				toanChan = false;
				break;
			}
		}
		if (toanChan) {
			printf("Dong %d\n", i);
		}
	}
}

// Bài 4: Tìm giá trị xuất hiện nhiều nhất trong ma trận
void timGiaTriXuatHienNhieuNhat(int matrix[][MAX_COL], int m, int n) {
	int maxCount = 0;
	int giaTriMax = matrix[0][0];

	// Tạo mảng đếm tần suất
	int count[MAX_ROW * MAX_COL] = { 0 };
	int giaTri[MAX_ROW * MAX_COL];
	int index = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			bool found = false;
			for (int k = 0; k < index; k++) {
				if (giaTri[k] == matrix[i][j]) {
					count[k]++;
					found = true;
					break;
				}
			}
			if (!found) {
				giaTri[index] = matrix[i][j];
				count[index++] = 1;
			}
		}
	}

	for (int i = 0; i < index; i++) {
		if (count[i] > maxCount) {
			maxCount = count[i];
			giaTriMax = giaTri[i];
		}
	}

	printf("Gia tri xuat hien nhieu nhat la: %d\n", giaTriMax);
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

// Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
void timSoNguyenToNhoNhat(int matrix[][MAX_COL], int m, int n) {
	int minSoNguyenTo = INT_MAX;
	bool timThay = false;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (laSoNguyenTo(matrix[i][j]) && matrix[i][j] < minSoNguyenTo) {
				minSoNguyenTo = matrix[i][j];
				timThay = true;
			}
		}
	}

	if (timThay) {
		printf("So nguyen to nho nhat la: %d\n", minSoNguyenTo);
	}
	else {
		printf("Khong co so nguyen to trong ma tran.\n");
	}
}
// Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k
void timPhanTuLonNhatNhoNhatTrongDong(int matrix[][MAX_COL], int m, int n, int k, bool timLonNhat) {
	if (k >= 0 && k < m) {
		int giaTri = matrix[k][0];
		for (int j = 1; j < n; j++) {
			if (timLonNhat) {
				if (matrix[k][j] > giaTri) {
					giaTri = matrix[k][j];
				}
			}
			else {
				if (matrix[k][j] < giaTri) {
					giaTri = matrix[k][j];
				}
			}
		}
		if (timLonNhat) {
			printf("Phan tu lon nhat trong dong %d la: %d\n", k, giaTri);
		}
		else {
			printf("Phan tu nho nhat trong dong %d la: %d\n", k, giaTri);
		}
	}
	else {
		printf("Dong %d khong ton tai.\n", k);
	}
}

// Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k
void timPhanTuLonNhatNhoNhatTrongCot(int matrix[][MAX_COL], int m, int n, int k, bool timLonNhat) {
	if (k >= 0 && k < n) {
		int giaTri = matrix[0][k];
		for (int i = 1; i < m; i++) {
			if (timLonNhat) {
				if (matrix[i][k] > giaTri) {
					giaTri = matrix[i][k];
				}
			}
			else {
				if (matrix[i][k] < giaTri) {
					giaTri = matrix[i][k];
				}
			}
		}
		if (timLonNhat) {
			printf("Phan tu lon nhat trong cot %d la: %d\n", k, giaTri);
		}
		else {
			printf("Phan tu nho nhat trong cot %d la: %d\n", k, giaTri);
		}
	}
	else {
		printf("Cot %d khong ton tai.\n", k);
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
			lietKeCotTongNhoNhat(matrix, m, n);
			break;
		case 2:
			lietKeDongNhieuSoHoanThienNhat(matrix, m, n);
			break;
		case 3:
			lietKeDongToanGiaTriChan(matrix, m, n);
			break;

		case 4:
			timGiaTriXuatHienNhieuNhat(matrix, m, n);
			break;
		case 5:
			timSoNguyenToNhoNhat(matrix, m, n);
			break;
		case 6:
		{
			int k;
			bool timLonNhat;
			printf("Nhap dong k: ");
			scanf_s("%d", &k);
			printf("Tim phan tu lon nhat (1) hay nho nhat (0)? ");
			scanf_s("%d", &timLonNhat);
			timPhanTuLonNhatNhoNhatTrongDong(matrix, m, n, k, timLonNhat);
		}
		break;
		case 7:
		{
			int k;
			bool timLonNhat;
			printf("Nhap cot k: ");
			scanf_s("%d", &k);
			printf("Tim phan tu lon nhat (1) hay nho nhat (0)? ");
			scanf_s("%d", &timLonNhat);
			timPhanTuLonNhatNhoNhatTrongCot(matrix, m, n, k, timLonNhat);
		}
		break;

		case 8:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (luaChon != 8);

	return 0;
}
