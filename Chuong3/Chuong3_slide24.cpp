#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
// Hàm kiểm tra chuỗi chỉ chứa ký số
int kiem_tra_chuoi_ky_so(const char* s) {
	while (*s) {
		if (!isdigit(*s)) return 0;  // Nếu không phải ký số, trả về 0
		s++;
	}
	return 1;  // Trả về 1 nếu toàn ký số
}


void chuyen_hoa_chu_cai_dau_tu(char* s) {
	int la_bat_dau = 1;
	while (*s) {
		if (la_bat_dau) {
			*s = toupper(*s);
			la_bat_dau = 0;
		}
		else {
			*s = tolower(*s);
		}
		if (*s == ' ') la_bat_dau = 1;
		s++;
	}
}

void tim_kiem_ten(const char* ho_ten, const char* ten) {
	const char* ptr = strstr(ho_ten, ten);
	if (ptr) {
		printf("Ten '%s' ton tai trong chuoi '%s'.\n", ten, ho_ten);
	}
	else {
		printf("Ten '%s' khong ton tai trong chuoi '%s'.\n", ten, ho_ten);
	}
}

int demKhoangTrang(const char* s)
{
	int count = 0;
	while (*s)
	{
		if (*s == ' ')
		{
			count++;
		}
		s++;
	}
	return count;
}

void xoa_khoang_trang_thua(char* s) {
	char* dst = s;
	int space_found = 0;

	while (*s) {
		if (*s == ' ') {
			if (!space_found) {
				*dst++ = *s;
				space_found = 1;
			}
		}
		else {
			*dst++ = *s;
			space_found = 0;
		}
		s++;
	}
	*dst = '\0';
}

void chen_chuoi_tai_vi_tri(char* s, const char* chuoi_chen, int vi_tri) {
	int len_s = strlen(s);
	int len_chen = strlen(chuoi_chen);

	if (vi_tri < 0 || vi_tri > len_s) {
		printf("Vi tri chen khong hop le.\n");
		return;
	}

	memmove(s + vi_tri + len_chen, s + vi_tri, len_s - vi_tri + 1);
	memcpy(s + vi_tri, chuoi_chen, len_chen);
}


void cat_ho_lot_ten(const char* ho_ten, char* ho, char* lot, char* ten) {
	char temp[200];
	size_t ho_size = 100;
	size_t lot_size = 100;
	size_t ten_size = 100;

	strcpy_s(temp, sizeof(temp), ho_ten);
	char* last_space = strrchr(temp, ' ');
	if (last_space) {
		strcpy_s(ten, ten_size, last_space + 1);
		*last_space = '\0';
	}
	else {
		ten[0] = '\0';
	}

	char* first_space = strchr(temp, ' ');
	if (first_space) {
		strncpy_s(ho, ho_size, temp, first_space - temp);
		ho[first_space - temp] = '\0';

		strcpy_s(lot, lot_size, first_space + 1);
	}
	else {
		ho[0] = '\0';
		lot[0] = '\0';
	}
}
// 8. Hàm xóa một chuỗi con từ chuỗi ban đầu
void xoa_chuoi_con(char* chuoi, const char* chuoi_con) {
	char* vi_tri = strstr(chuoi, chuoi_con);
	int len_chuoi_con = strlen(chuoi_con);

	if (vi_tri) {
		memmove(vi_tri, vi_tri + len_chuoi_con, strlen(vi_tri + len_chuoi_con) + 1);

		// Xóa khoảng trắng dư thừa nếu có
		int len_chuoi = strlen(chuoi);
		for (int i = 0; i < len_chuoi; i++) {
			if (chuoi[i] == ' ' && (i == 0 || chuoi[i + 1] == ' ' || chuoi[i + 1] == '\0')) {
				memmove(&chuoi[i], &chuoi[i + 1], len_chuoi - i);
				i--;
				len_chuoi--;
			}
		}

		// Xóa khoảng trắng cuối chuỗi nếu có
		if (len_chuoi > 0 && chuoi[len_chuoi - 1] == ' ') {
			chuoi[len_chuoi - 1] = '\0';
		}
	}
	else {
		printf("Chuoi con '%s' khong ton tai trong chuoi ban dau.\n", chuoi_con);
	}
}
// 9. liet ke xem ký tự xuất hiện mấy lần
void liet_ke_ky_tu(const char* s) {
	int tan_suat[256] = { 0 };

	for (int i = 0; s[i]; i++) {
		tan_suat[(unsigned char)s[i]]++;
	}

	printf("Danh sach ky tu va so lan xuat hien:\n");
	for (int i = 0; i < 256; i++) {
		if (tan_suat[i] > 0) {
			printf("Ky tu '%c' xuat hien %d lan.\n", i, tan_suat[i]);
		}
	}
}
int main() {
	int lua_chon;
	printf("----------MeNu------------ :\n");
	printf("1. Kiem tra chuoi co chua toan ky so\n");
	printf("2. Viet ham đem co bao nhieu khoang trang trong chuoi\n");
	printf("3. Xoa khoang trang thua trong chuoi\n");
	printf("4. Chuyen doi ky tu dau tien cua moi tu thanh chu in hoa\n");
	printf("5. Tim kiem ten trong chuoi ho ten\n");
	printf("6. Cat chuoi ho ten thanh ho lot va ten\n");
	printf("7. Viet chuong trinh chen mot chu vao vi tri nguoi dung yeu cau\n");
	printf("8. Xoa chuoi con\n");
	printf("9. Liet ke moi ky tu trong chuoi xuat hien may lan\n");
	printf("10. Tim ky tu xuat hien nhieu nhat trong chuoi\n");
	do {
		printf("\nNhap lua chon cua ban: ");
		scanf_s("%d", &lua_chon);

		switch (lua_chon) {
		case 1: {
			char s[100];
			printf("Nhap chuoi can kiem tra: ");
			scanf_s(" %[^\n]", s, sizeof(s));  // Đọc chuỗi có khoảng trắng
			if (kiem_tra_chuoi_ky_so(s)) {
				printf("Chuoi chua toan ky so.\n");
			}
			else {
				printf("Chuoi khong chua toan ky so.\n");
			}
			break;
		}


		case 2: {
			char s[100];
			printf("Nhap chuoi can kiem tra: ");
			scanf_s(" %[^\n]", s, sizeof(s));  // Đọc chuỗi có khoảng trắng
			printf("So khoang trang trong chuoi la: %d", demKhoangTrang(s));
			break;
		}
		case 3: {
			char s[100];
			printf("Nhap chuoi can xoa khoang trang thua: ");
			while (getchar() != '\n');
			fgets(s, sizeof(s), stdin);
			s[strcspn(s, "\n")] = '\0';
			xoa_khoang_trang_thua(s);
			printf("Chuoi sau khi xoa khoang trang thua: %s\n", s);
			break;
		}
		case 4: {
			char ho_ten[100];
			printf("Nhap chuoi ho ten: ");
			while (getchar() != '\n');
			fgets(ho_ten, sizeof(ho_ten), stdin);
			ho_ten[strcspn(ho_ten, "\n")] = '\0';
			chuyen_hoa_chu_cai_dau_tu(ho_ten);
			printf("Chuoi sau khi chuyen doi: %s\n", ho_ten);
			break;
		}

		case 5: {
			char ho_ten[100], ten[50];
			printf("Nhap chuoi ho ten: ");
			scanf_s(" %[^\n]", ho_ten, sizeof(ho_ten));
			printf("Nhap ten can tim: ");
			scanf_s(" %[^\n]", ten, sizeof(ten));
			tim_kiem_ten(ho_ten, ten);
			break;
		}
		case 6: {
			char ho_ten[200], ho[100], lot[100], ten[100];
			printf("Nhap chuoi ho ten: ");
			while (getchar() != '\n');
			fgets(ho_ten, sizeof(ho_ten), stdin);
			ho_ten[strcspn(ho_ten, "\n")] = '\0';
			cat_ho_lot_ten(ho_ten, ho, lot, ten);

			printf("Ho: %s\n", ho);
			printf("Lot: %s\n", lot);
			printf("Ten: %s\n", ten);
			break;
		}
		case 7: {
			char s[100], chuoi_chen[50];
			int vi_tri;
			printf("Nhap chuoi ban dau: ");
			while (getchar() != '\n');
			fgets(s, sizeof(s), stdin);
			s[strcspn(s, "\n")] = '\0';
			printf("Nhap chuoi can chen: ");
			fgets(chuoi_chen, sizeof(chuoi_chen), stdin);
			chuoi_chen[strcspn(chuoi_chen, "\n")] = '\0';
			printf("Nhap vi tri chen: ");
			scanf_s("%d", &vi_tri);
			chen_chuoi_tai_vi_tri(s, chuoi_chen, vi_tri);
			printf("Chuoi sau khi chen: %s\n", s);
			break;
		}

		case 8:
		{
			char s[100], s2[30];
			printf("Nhap chuoi ban dau: ");
			scanf_s(" %[^\n]", s, sizeof(s));
			printf("Nhap chuoi can xoa : ");
			scanf_s(" %[^\n]", s2, sizeof(s2));
			xoa_chuoi_con(s, s2);
			printf("Chuoi sau khi xoa: %s\n", s);
			break;
		}
		case 9: {
			char s[100];
			printf("Nhap chuoi: ");
			while (getchar() != '\n');
			fgets(s, sizeof(s), stdin);
			s[strcspn(s, "\n")] = '\0';
			liet_ke_ky_tu(s);
			break;
		}
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	} while (lua_chon != 0);
	getchar();
	return 0;
}
