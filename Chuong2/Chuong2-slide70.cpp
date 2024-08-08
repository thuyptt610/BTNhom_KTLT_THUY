#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Cấu trúc lưu trữ thông tin sinh viên
typedef struct {
	int stt;
	char ma_so_sv[10];
	char ho_ten[50];
	float diem_tieu_luan;
	float diem_thi;
	float diem_tong_ket;
	float diem_he_4;
} SinhVien;

// Hàm nhập danh sách sinh viên
void nhap_danh_sach_sinh_vien(SinhVien ds[], int* n) {
	printf("Nhap so luong sinh vien: ");
	scanf_s("%d", n);

	for (int i = 0; i < *n; i++) {
		printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
		ds[i].stt = i + 1;
		printf("Ma so sinh vien: ");
		scanf_s("%s", ds[i].ma_so_sv, (unsigned)_countof(ds[i].ma_so_sv));
		printf("Ho ten sinh vien: ");
		fgetc(stdin); // Xóa ký tự newline trong bộ đệm nhập
		fgets(ds[i].ho_ten, sizeof(ds[i].ho_ten), stdin);
		ds[i].ho_ten[strcspn(ds[i].ho_ten, "\n")] = '\0'; // Loại bỏ ký tự newline ở cuối chuỗi
		printf("Diem tieu luan: ");
		scanf_s("%f", &ds[i].diem_tieu_luan);
		printf("Diem thi ket thuc mon: ");
		scanf_s("%f", &ds[i].diem_thi);
		ds[i].diem_tong_ket = (float)(ds[i].diem_tieu_luan * 0.3 + ds[i].diem_thi * 0.7);
	}
}
// Hàm xuất danh sách sinh viên
void xuat_danh_sach_sinh_vien(SinhVien ds[], int n) {
	printf("Danh sach sinh vien:\n");
	printf("STT\tMa So\tHo Ten\t\t\tDiem Tieu Luan\tDiem Thi\tDiem Tong Ket\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", ds[i].stt, ds[i].ma_so_sv, ds[i].ho_ten, ds[i].diem_tieu_luan, ds[i].diem_thi, ds[i].diem_tong_ket);
	}
}

int main() {
	SinhVien ds[MAX_STUDENTS];
	int n, lua_chon;

	//doc_tu_file(ds, &n, "sinhvien.txt");
	printf("======================= MeNu ======================= \n");
	printf("1. Nhap danh sach sinh vien\n");
	printf("2. Xuat danh sach sinh vien\n");
	printf("3. Tinh diem tong ket\n");
	printf("4. Tim sinh vien co diem cao nhat va thap nhat\n");
	printf("5. Dem so sinh vien dat va khong dat\n");
	printf("6. Qui doi diem sang he 4\n");
	printf("7. Sap xep danh sach\n");
	printf("8. Tinh diem trung binh\n");
	printf("9. Ghi danh sach sinh vien vao file\n");
	printf("0. Thoat\n");
	printf("=================================================== \n");
	do {

		printf("Nhap lua chon: ");
		scanf_s("%d", &lua_chon);

		switch (lua_chon) {
		case 1:
			nhap_danh_sach_sinh_vien(ds, &n);
			break;
		case 2:
			xuat_danh_sach_sinh_vien(ds, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (lua_chon != 0);

	return 0;
}
