#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    clock_t start_time, end_time;
    start_time = clock();
    selection_sort(arr, n);
    end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime complexity: O(n^2)\n");
    printf("Execution time: %f seconds\n", total_time);

    return 0;
}

