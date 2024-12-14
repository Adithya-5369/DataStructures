#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucketSort(float arr[], int n) {
    struct Bucket {
        int count;
        float* values;
    } buckets[BUCKET_SIZE];

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].count = 0;
        buckets[i].values = malloc(n * sizeof(float));
    }

    for (int i = 0; i < n; i++) {
        int index = (int)(BUCKET_SIZE * arr[i]);
        buckets[index].values[buckets[index].count++] = arr[i];
    }

    for (int i = 0; i < BUCKET_SIZE; i++) {
        int count = buckets[i].count;
        for (int j = 0; j < count - 1; j++) {
            for (int k = 0; k < count - j - 1; k++) {
                if (buckets[i].values[k] > buckets[i].values[k + 1]) {
                    float temp = buckets[i].values[k];
                    buckets[i].values[k] = buckets[i].values[k + 1];
                    buckets[i].values[k + 1] = temp;
                }
            }
        }
    }

    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].values[j];
        }
        free(buckets[i].values);
    }
}


int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    printf("Bucket Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%f ", arr[i]);
    printf("\n");
    return 0;
}