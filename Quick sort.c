#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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
        quickSort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        printf("Quick Sort | N=%d | Time=%f sec\n", n, time_taken);
    }

    return 0;
}
