#include <stdio.h>
#include <stdlib.h>

// 全局数组
int* arr;

// 合并两个已排序的子数组
void merge(int left, int mid, int right) {
    int n1 = mid - left+1;
    int n2 = right - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    // 填充左子数组
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    // 填充右子数组
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1+ j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

// 归并排序递归函数
void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left+(right - left)/2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}


int main() {
    int n;
    n = 8;
    arr = (int*)malloc(n * sizeof(int));
    arr[0] = 5;
    arr[1] = 3;
    arr[2] = 8;
    arr[3] = 4;
    arr[4] = 2;
    arr[5] = 7;
    arr[6] = 1;
    arr[7] = 6;
    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergeSort(0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}