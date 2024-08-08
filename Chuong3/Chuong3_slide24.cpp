#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

//1. Hàm ki?m tra chu?i ch? ch?a ký s?
int kiem_tra_chuoi_ky_so(const char* s) {
	while (*s) {
		if (!isdigit(*s)) return 0;  
		s++;
	}
	return 1;  
}



int main() {
	int lua_chon;
	printf("----------MeNu------------ :\n");
	printf("1. Kiem tra chuoi co chua toan ky so\n");
	printf("2. Viet ham ?em co bao nhieu khoang trang trong chuoi\n");
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
			scanf_s(" %[^\n]", s, sizeof(s));  
			if (kiem_tra_chuoi_ky_so(s)) {
				printf("Chuoi chua toan ky so.\n");
			}
			else {
				printf("Chuoi khong chua toan ky so.\n");
			}
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
