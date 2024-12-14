/* Question:-
Construct a time and space efficient algorithm to continuously keep track of the seventh smallest integer (among the integers seen so far) in a never-ending stream of continuously flowing integers. Use an appropriate data structure to solve this problem.
*/

#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 7

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the max heap
void maxHeapify(int heap[], int i, int size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, largest, size);
    }
}

// Insert an element into the max heap
void insertMaxHeap(int heap[], int *size, int value) {
    heap[(*size)++] = value; // Add at the end
    int i = *size - 1;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

// Replace root of max heap with a new value
void replaceRoot(int heap[], int value, int size) {
    heap[0] = value;
    maxHeapify(heap, 0, size);
}

void trackSeventhSmallest(int stream[], int n) {
    int maxHeap[HEAP_SIZE]; 
    int size = 0;

    for (int i = 0; i < n; i++) {
        if (size < HEAP_SIZE) {
            insertMaxHeap(maxHeap, &size, stream[i]);
        } else if (stream[i] < maxHeap[0]) {
            replaceRoot(maxHeap, stream[i], size);
        }

        if (size == HEAP_SIZE) {
            printf("7th smallest so far: %d\n", maxHeap[0]);
        } else {
            printf("Less than 7 elements seen so far\n");
        }
    }
}

int main() {
    int stream[] = {15, 2, 7, 20, 1, 5, 9, 3, 6, 8, 4, 12, 11, 10, 13};
    int n = sizeof(stream) / sizeof(stream[0]);

    trackSeventhSmallest(stream, n);
    return 0;
}