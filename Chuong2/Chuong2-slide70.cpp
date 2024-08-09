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
	printf("STT\tMa So\tHo Ten\t\tDiem Tieu Luan\tDiem Thi\tDiem Tong Ket\tDiem He 4\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%s\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", ds[i].stt, ds[i].ma_so_sv, ds[i].ho_ten, ds[i].diem_tieu_luan, ds[i].diem_thi, ds[i].diem_tong_ket, ds[i].diem_he_4);
	}
}

// Hàm tìm sinh viên có điểm tổng kết cao nhất và thấp nhất
void tim_sinh_vien_cao_nhat_thap_nhat(SinhVien ds[], int n) {
	int cao_nhat_idx = 0, thap_nhat_idx = 0;

	for (int i = 1; i < n; i++) {
		if (ds[i].diem_tong_ket > ds[cao_nhat_idx].diem_tong_ket) {
			cao_nhat_idx = i;
		}
		if (ds[i].diem_tong_ket < ds[thap_nhat_idx].diem_tong_ket) {
			thap_nhat_idx = i;
		}
	}

	printf("Sinh vien co diem tong ket cao nhat:\n");
	printf("STT: %d\nMa so: %s\nHo ten: %s\nDiem tong ket: %.2f\n",
		ds[cao_nhat_idx].stt, ds[cao_nhat_idx].ma_so_sv, ds[cao_nhat_idx].ho_ten, ds[cao_nhat_idx].diem_tong_ket);

	printf("Sinh vien co diem tong ket thap nhat:\n");
	printf("STT: %d\nMa so: %s\nHo ten: %s\nDiem tong ket: %.2f\n",
		ds[thap_nhat_idx].stt, ds[thap_nhat_idx].ma_so_sv, ds[thap_nhat_idx].ho_ten, ds[thap_nhat_idx].diem_tong_ket);
}

// Hàm đếm số sinh viên đạt và không đạt
void dem_sinh_vien_dat_khong_dat(SinhVien ds[], int n) {
	int dat = 0, khong_dat = 0;

	for (int i = 0; i < n; i++) {
		if (ds[i].diem_tong_ket >= 5.0) {
			dat++;
		}
		else {
			khong_dat++;
		}
	}

	printf("So sinh vien dat: %d\n", dat);
	printf("So sinh vien khong dat: %d\n", khong_dat);
}

// Hàm tính điểm hệ 4
void tinh_diem_he_4(SinhVien ds[], int n) {
	for (int i = 0; i < n; i++) {
		float diem = ds[i].diem_tong_ket;
		if (diem >= 8.5) {
			ds[i].diem_he_4 = 4.0;
		}
		else if (diem >= 7.0) {
			ds[i].diem_he_4 = 3.0;
		}
		else if (diem >= 5.5) {
			ds[i].diem_he_4 = 2.0;
		}
		else if (diem >= 4.0) {
			ds[i].diem_he_4 = 1.0;
		}
		else {
			ds[i].diem_he_4 = 0.0;
		}
	}
}

// Hàm sắp xếp danh sách sinh viên tăng/ giảm theo điểm tổng kết
void sap_xep_danh_sach(SinhVien ds[], int n, int tang) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((tang && ds[i].diem_tong_ket > ds[j].diem_tong_ket) || (!tang && ds[i].diem_tong_ket < ds[j].diem_tong_ket)) {
				SinhVien temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}
// Hàm tính điểm trung bình của tất cả sinh viên
float tinh_diem_trung_binh(SinhVien ds[], int n) {
	float tong_diem = 0.0;

	for (int i = 0; i < n; i++) {
		tong_diem += ds[i].diem_tong_ket;
	}

	return tong_diem / n;
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
	printf("6. Quy doi diem tong ket sang he 4\n");
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
		case 3:
			printf("Diem tong ket da duoc tinh trong qua trinh nhap du lieu.\n");
			break;
		case 4:
			tim_sinh_vien_cao_nhat_thap_nhat(ds, n);
			break;
		case 5:
			dem_sinh_vien_dat_khong_dat(ds, n);
			break;
		case 6:
			tinh_diem_he_4(ds, n);
			xuat_danh_sach_sinh_vien(ds, n);
			break;
		case 7:
			printf("1. Sap xep tang dan\n2. Sap xep giam dan\nNhap lua chon: ");
			int tang;
			scanf_s("%d", &tang);
			sap_xep_danh_sach(ds, n, tang == 1);
			tinh_diem_he_4(ds, n);
			xuat_danh_sach_sinh_vien(ds, n);
			break;
		case 8:
			printf("Diem trung binh cua tat ca sinh vien: %.2f\n", tinh_diem_trung_binh(ds, n));
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
