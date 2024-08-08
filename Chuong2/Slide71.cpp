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

	// T�nh ?i?m trung b�nh t�ch l?y
	float tongDiem = 0.0;
	int tongTinChi = 0;
	for (int i = 0; i < MAX_MON_HOC; i++) {
		tongDiem += sv->monHoc[i].diem * sv->monHoc[i].soTinChi;
		tongTinChi += sv->monHoc[i].soTinChi;
	}
	sv->diemTrungBinhTichLuy = tongDiem / tongTinChi;
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
