#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
// Insertion Sort function 
void insertionSort(int arr[], int n) { 
    
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1; 
 
        // Move elements greater than key one step ahead 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
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
        printf("Memory alloca on failed\n"); 
        return 1; 
    } 
 
    generateRandomArray(arr, n); 
    clock_t start = clock(); 
    for(int i = 0; i < 100000; i++) {   // run more times
    insertionnSort(arr, n); 
    } 
    clock_t end = clock(); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 100000.0; 
    printf("Time taken to sort %d elements using Insertion Sort: %.6f seconds\n", n, time_taken); 
    free(arr); 
    return 0; 
}