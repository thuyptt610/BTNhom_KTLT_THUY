#include <stdio.h>
#include<stdlib.h>

// Đệ quy: Tim kiem nhi phan tren mang so nguyen
int binarySearchRecursive(int arr[], int left, int right, int x);

int main() {
    int n, x;

    printf("Nhap so luong phan tu cua mang: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1; 
    }

   
    printf("Nhap cac phan tu cua mang (da sap xep):\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

   
    printf("Nhap gia tri x can tim: ");
    scanf_s("%d", &x);

   
    int result = binarySearchRecursive(arr, 0, n - 1, x);

    // In k?t qu?
    if (result != -1) {
        printf("Gia tri %d duoc tim thay tai chi so %d.\n", x, result);
    }
    else {
        printf("Gia tri %d khong ton tai trong mang.\n", x);
    }

    return 0;
}

// Hàm đệ quy tìm kiếm nhị phân
int binarySearchRecursive(int arr[], int left, int right, int x) {
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == x) {
        return mid;
    }

    else if (x < arr[mid]) {
        return binarySearchRecursive(arr, left, mid - 1, x);
    }

    else {
        return binarySearchRecursive(arr, mid + 1, right, x);
    }
}
