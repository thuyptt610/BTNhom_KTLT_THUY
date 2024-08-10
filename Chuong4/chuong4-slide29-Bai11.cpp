#include <stdio.h>

// Xuat day Fibonacci

int fibonacciRecursive(int n);
void printFibonacci(int n);

int main() {
    int n;
    do {

        printf("Nhap so luong so Fibonacci can xuat: ");
        scanf_s("%d", &n);

        if (n <= 0) {
            printf("So luong phan tu phai la so nguyen duong!\n");
        }
    } while (n <= 0);

    printFibonacci(n);

    return 0;
}

// Hàm đệ quy tính số Fibonacci thứ n
int fibonacciRecursive(int n) {
    if (n <= 2) {
        return 1; 
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Hàm xuất dãy Fibonacci 
void printFibonacci(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", fibonacciRecursive(i));
    }
    printf("\n");
}
