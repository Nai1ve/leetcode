#include <stdio.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int b[], int left, int mid, int right);
void copy(int arr[], int b[], int left, int right);

void mergeSort(int arr[], int left, int right)
{
    int mid = (left + right) / 2;
    if (left < right)
    {
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        int b[right - left + 1];
        merge(arr, b, left, mid, right);
        copy(arr, b, left, right);
    }

    return;
}

void merge(int arr[], int b[], int left, int mid, int right)
{

    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right)
    {
        b[k] = arr[j];
        j++;
        k++;
    }
    return;
}

void copy(int arr[], int b[], int left, int right)
{
    int j = 0;
    for (int i = left; i <= right; i++){
        arr[i] = b[j];
        j++;
    }
}


int main(){
    int arr[] = {3,5,8,4,2,6,7,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
