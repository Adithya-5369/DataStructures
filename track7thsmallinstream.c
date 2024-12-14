/* Question:-
Construct a time and space efficient algorithm to continuously keep track of the seventh smallest integer (among the integers seen so far) in a never-ending stream of continuously flowing integers. Use an appropriate data structure to solve this problem.
*/

#include <stdio.h>
#include <stdlib.h>

#define HEAP_CAPACITY 7

void swap_elements(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify_down(int arr[], int idx, int size) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;
    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != idx) {
        swap_elements(&arr[idx], &arr[largest]);
        heapify_down(arr, largest, size);
    }
}

void insert_into_heap(int arr[], int *size, int value) {
    arr[(*size)++] = value;
    int idx = *size - 1;

    while (idx > 0 && arr[(idx - 1) / 2] < arr[idx]) {
        swap_elements(&arr[(idx - 1) / 2], &arr[idx]);
        idx = (idx - 1) / 2;
    }
}

void replace_root(int arr[], int value, int size) {
    arr[0] = value;
    heapify_down(arr, 0, size);
}

void track_seventh_smallest(int stream[], int len) {
    int maxHeap[HEAP_CAPACITY];
    int heap_size = 0;

    for (int i = 0; i < len; i++) {
        if (heap_size < HEAP_CAPACITY) {
            insert_into_heap(maxHeap, &heap_size, stream[i]);
        } else if (stream[i] < maxHeap[0]) {
            replace_root(maxHeap, stream[i], heap_size);
        }

        if (heap_size == HEAP_CAPACITY) {
            printf("7th smallest so far: %d\n", maxHeap[0]);
        } else {
            printf("Less than 7 elements seen so far\n");
        }
    }
}

int main() {
    int stream[] = {15, 2, 7, 20, 1, 5, 9, 3, 6, 8, 4, 12, 11, 10, 13};
    int n = sizeof(stream) / sizeof(stream[0]);

    track_seventh_smallest(stream, n);
    return 0;
}
