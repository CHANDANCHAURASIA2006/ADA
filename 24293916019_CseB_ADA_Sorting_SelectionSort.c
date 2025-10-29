#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
// Selection Sort function 
void selectionSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        int minIndex = i; 
 
        // Find the minimum element in unsorted array 
        for (int j = i + 1; j < n; j++) { 
            if (arr[j] < arr[minIndex]) { 
                minIndex = j; 
            } 
        } 
 
        // Swap the found minimum with the first element 
        if (minIndex != i) { 
            int temp = arr[i]; 
            arr[i] = arr[minIndex]; 
            arr[minIndex] = temp; 
        } 
    } 
} 
 
// Generate random array 
void generateRandomArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) { 
        arr[i] = rand() % 1000; // random integer between 0–999 
    } 
} 
 
int main() { 
    int n; 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    int *arr = (int*)malloc(n * sizeof(int)); 
    if (arr == NULL) { 
        printf("Memory allocation failed\n"); 
        return 1; 
    } 
 
    generateRandomArray(arr, n); 
    clock_t start = clock(); 
    for (int i = 0; i < 100000; i++) {   // run multiple time
        selectionSort(arr, n); 
    } 
    clock_t end = clock(); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 100000.0; 
    printf("Time taken to sort %d elements using Selection Sort: %.6f seconds\n", n, time_taken); 
    free(arr); 
    return 0; 
} 
