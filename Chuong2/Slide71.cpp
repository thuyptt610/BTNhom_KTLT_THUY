#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MON_HOC 2
#define MAX_SINH_VIEN 100

typedef struct {
	char maMon[10];
	char tenMon[50];
	int soTinChi;
	float diem;
} MonHoc;

typedef struct {
	char maSoSv[10];
	char hoTen[50];
	MonHoc monHoc[MAX_MON_HOC];
	float diemTrungBinhTichLuy;
} SinhVien;

void nhapMonHoc(MonHoc* monHoc) {
	printf("Nhap ma mon hoc: ");
	scanf_s("%s", monHoc->maMon, sizeof(monHoc->maMon));
	printf("Nhap ten mon hoc: ");
	scanf_s(" %[^\n]", monHoc->tenMon, sizeof(monHoc->tenMon));
	printf("Nhap so tin chi: ");
	scanf_s("%d", &monHoc->soTinChi);
	printf("Nhap diem: ");
	scanf_s("%f", &monHoc->diem);
}

void nhapSinhVien(SinhVien* sv) {
	printf("Nhap ma so sinh vien: ");
	scanf_s("%s", sv->maSoSv, sizeof(sv->maSoSv));
	printf("Nhap ho ten sinh vien: ");
	scanf_s(" %[^\n]", sv->hoTen, sizeof(sv->hoTen));

	printf("Nhap thong tin cac mon hoc:\n");
	for (int i = 0; i < MAX_MON_HOC; i++) {
		printf("Mon hoc %d:\n", i + 1);
		nhapMonHoc(&sv->monHoc[i]);
	}

	// Tính điểm trung bình tích lũy
	float tongDiem = 0.0;
	int tongTinChi = 0;
	for (int i = 0; i < MAX_MON_HOC; i++) {
		tongDiem += sv->monHoc[i].diem * sv->monHoc[i].soTinChi;
		tongTinChi += sv->monHoc[i].soTinChi;
	}
	sv->diemTrungBinhTichLuy = tongDiem / tongTinChi;
}
void xuatMonHoc(const MonHoc* monHoc) {
	printf("%-10s %-50s %d %.2f\n", monHoc->maMon, monHoc->tenMon, monHoc->soTinChi, monHoc->diem);
}

void xuatSinhVien(const SinhVien* sv) {
	printf("Ma so sinh vien: %s\n", sv->maSoSv);
	printf("Ho ten: %s\n", sv->hoTen);
	printf("Thong tin cac mon hoc:\n");
	printf("%-10s %-50s %-10s %s\n", "Ma Mon", "Ten Mon", "Tin Chi", "Diem");
	for (int i = 0; i < MAX_MON_HOC; i++) {
		xuatMonHoc(&sv->monHoc[i]);
	}
	printf("Diem trung binh tich luy: %.2f\n", sv->diemTrungBinhTichLuy);
}
//cau3: 

int timSinhVien(const SinhVien ds[], int n, const char* maSoSv) {
	for (int i = 0; i < n; i++) {
		if (strcmp(ds[i].maSoSv, maSoSv) == 0) {
			return i;
		}
	}
	return -1;  // Không tìm thấy
}
//4
int timSinhVienCaoNhat(const SinhVien ds[], int n) {
	int idx = 0;
	for (int i = 1; i < n; i++) {
		if (ds[i].diemTrungBinhTichLuy > ds[idx].diemTrungBinhTichLuy) {
			idx = i;
		}
	}
	return idx;
}
//5
int timSinhVienThapNhat(const SinhVien ds[], int n) {
	int idx = 0;
	for (int i = 1; i < n; i++) {
		if (ds[i].diemTrungBinhTichLuy < ds[idx].diemTrungBinhTichLuy) {
			idx = i;
		}
	}
	return idx;
}
//6

void themSinhVien(SinhVien ds[], int* n, const SinhVien* sv) {
	if (*n < MAX_SINH_VIEN) {
		ds[*n] = *sv;
		(*n)++;
	}
	else {
		printf("Danh sach sinh vien da day.\n");
	}
}
//7
void xoaSinhVien(SinhVien ds[], int* n, const char* maSoSv) {
	int idx = timSinhVien(ds, *n, maSoSv);
	if (idx != -1) {
		for (int i = idx; i < *n - 1; i++) {
			ds[i] = ds[i + 1];
		}
		(*n)--;
	}
	else {
		printf("Khong tim thay sinh vien.\n");
	}
}
//8

void sapXepSinhVien(SinhVien ds[], int n, int tang) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((tang && ds[i].diemTrungBinhTichLuy > ds[j].diemTrungBinhTichLuy) ||
				(!tang && ds[i].diemTrungBinhTichLuy < ds[j].diemTrungBinhTichLuy)) {
				SinhVien temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}
//9
void xepLoaiHocTap(const SinhVien* sv) {
	if (sv->diemTrungBinhTichLuy >= 8.5) {
		printf("Xep loai: Xuat sac\n");
	}
	else if (sv->diemTrungBinhTichLuy >= 7.0) {
		printf("Xep loai: Gioi\n");
	}
	else if (sv->diemTrungBinhTichLuy >= 5.5) {
		printf("Xep loai: Kha\n");
	}
	else if (sv->diemTrungBinhTichLuy >= 4.0) {
		printf("Xep loai: Trung binh\n");
	}
	else {
		printf("Xep loai: Yeu\n");
	}
}

int main() {
	SinhVien ds[MAX_SINH_VIEN];
	int n = 0;
	int luaChon;

	do {
		printf("----------MeNu------------\n");
		printf("1. Nhap danh sach sinh vien\n");
		printf("2. Xuat danh sach sinh vien\n");
		printf("3. Tim sinh vien theo ma so\n");
		printf("4. Tim sinh vien co diem trung binh cao nhat\n");
		printf("5. Tim sinh vien co diem trung binh thap nhat\n");
		printf("6. Them sinh vien\n");
		printf("7. Xoa sinh vien\n");
		printf("8. Sap xep danh sach sinh vien\n");
		printf("9. Xep loai hoc tap cua sinh vien\n");
		printf("10. Thong ke so mon dau ro\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &luaChon);

		switch (luaChon) {
		case 1:
			printf("Nhap so sinh vien: ");
			scanf_s("%d", &n);
			for (int i = 0; i < n; i++) {
				printf("Nhap thong tin sinh vien %d:\n", i + 1);
				nhapSinhVien(&ds[i]);
			}
			break;
		case 2:
			for (int i = 0; i < n; i++) {
				printf("Thong tin sinh vien %d:\n", i + 1);
				xuatSinhVien(&ds[i]);
				printf("\n");
			}
			break;
			break;
		case 3: {
			char maSoSv[10];
			printf("Nhap ma so sinh vien can tim: ");
			scanf_s("%s", maSoSv, sizeof(maSoSv));
			int idx = timSinhVien(ds, n, maSoSv);
			if (idx != -1) {
				xuatSinhVien(&ds[idx]);
			}
			else {
				printf("Khong tim thay sinh vien.\n");
			}
			break;
		}
		case 4: {
			int idx = timSinhVienCaoNhat(ds, n);
			printf("Sinh vien co diem trung binh cao nhat:\n");
			xuatSinhVien(&ds[idx]);
			break;
		}
		case 5: {
			int idx = timSinhVienThapNhat(ds, n);
			printf("Sinh vien co diem trung binh thap nhat:\n");
			xuatSinhVien(&ds[idx]);
			break;
		}
		case 6: {
			SinhVien sv;
			printf("Nhap thong tin sinh vien can them:\n");
			nhapSinhVien(&sv);
			themSinhVien(ds, &n, &sv);
			break;
		}
		case 7: {
			char maSoSv[10];
			printf("Nhap ma so sinh vien can xoa: ");
			scanf_s("%s", maSoSv, sizeof(maSoSv));
			xoaSinhVien(ds, &n, maSoSv);
			break;
		}
		case 8: {
			printf("1. Sap xep tang dan\n2. Sap xep giam dan\nNhap lua chon: ");
			int tang;
			scanf_s("%d", &tang);
			sapXepSinhVien(ds, n, tang == 1);
			printf("Danh sach sinh vien sau khi sap xep:\n");
			for (int i = 0; i < n; i++) {
				xuatSinhVien(&ds[i]);
				printf("\n");
			}
			break;
		}
		case 9: {
			char maSoSv[10];
			printf("Nhap ma so sinh vien can xep loai: ");
			scanf_s("%s", maSoSv, sizeof(maSoSv));
			int idx = timSinhVien(ds, n, maSoSv);
			if (idx != -1) {
				xepLoaiHocTap(&ds[idx]);
			}
			else {
				printf("Khong tim thay sinh vien.\n");
			}
			break;
		}
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}

	} while (luaChon != 0);

	return 0;
}
