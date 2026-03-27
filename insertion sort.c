#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000};

    printf("Student Name: Safat\n");
    printf("Student ID: C233130\n\n");

    for(int s = 0; s < 5; s++) {
        int n = sizes[s];
        int arr[n];

        for(int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }

        clock_t start = clock();
        insertionSort(arr, n);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Insertion Sort | N=%d | Time=%f sec\n", n, time_taken);
    }

    return 0;
}
