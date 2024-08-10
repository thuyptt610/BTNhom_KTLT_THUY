#include <stdio.h>

// TH1: tinh f(5)
// TH2: tinh f(n)

int f(int n);

int main() {
    int n;

    do {

        printf("Nhap so nguyen duong n: ");
        scanf_s("%d", &n);

        if (n < 1) {
            printf("n phai la so nguyen duong!\n");

        }
    } while (n < 1);

   
    int result = f(n);
    printf("1. Gia tri cua f(%d) la: %d\n", n, result);



    // TH2: f(5)
    int n1 = 5; 
    int result1 = f(n1);
    printf("2. Gia tri cua f(%d) la: %d\n", n1, result1);

    return 0;
}


// Hàm tính giá trị của f(n) theo công thức đệ quy
int f(int n) {
    if (n == 1) return 1;
    if (n % 2 == 0) {
        return 2 * f(n / 2);
    }
    else {
        return 2 * f(n / 2) + 3 * f(n / 2 + 1);
    }
}
