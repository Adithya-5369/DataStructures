#include <stdio.h>
#include <string.h>
#define RANGE 255

void countSort(int arr[], int n) {
    int output[n];
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));
    for (i = 0; i < n; i++)
        count[arr[i]]++;
    for (i = 1; i <= RANGE; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    countSort(arr, n);
    printf("Counting Sorted array: \n");
    printArray(arr, n);
    return 0;
}