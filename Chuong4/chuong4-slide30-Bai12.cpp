#include <stdio.h>

// Tim so Fibonacci gan nhat nho hon so nguyen to trong mang mot chieu
int fibonacciRecursive(int n);
int findLargestFibonacciLessThan(int n, int fib, int prevFib);
int largestFibonacciLessThan(int n);
int largestFibonacciLessThanIterative(int n);
int main() {
    int n;

    do {
        printf("Nhap so nguyen n: ");
        scanf_s("%d", &n);

        if (n <= 0) {
            printf("So nguyen to phai la so duong!\n");

        }
    } while (n <= 0);

    int result = largestFibonacciLessThan(n);
    printf("So Fibonacci lon nhat nho hon %d la: %d\n", n, result);

    // khu de quy
    int result1 = largestFibonacciLessThanIterative(n);
    printf("So Fibonacci lon nhat nho hon %d la: %d\n", n, result1);

    return 0;
}


// Hàm de quy tim Fibonacci thu n
int fibonacciRecursive(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Hàm tìm so Fibonacci lon nhat nho hon so nguyen n
int findLargestFibonacciLessThan(int n, int fib, int prevFib) {
    if (fib >= n) {
        return prevFib; // Tra ve Fibonacci truoc so hien tai >= n
    }
    return findLargestFibonacciLessThan(n, fib + prevFib, fib); // Tính so Fibonacci tiep theo
}

// Hàm tìm so Fibonacci lon nhat nho hon so nguyên  n
int largestFibonacciLessThan(int n) {
    return findLargestFibonacciLessThan(n, 1, 0); // Bat dau voi F(1) = 1 và F(0) = 0
}

// Khu de quy
int largestFibonacciLessThanIterative(int n) {
    int fib = 1, prevFib = 0, temp;

    while (fib < n) {
        temp = fib;
        fib = fib + prevFib;
        prevFib = temp;
    }

    return prevFib; 
}