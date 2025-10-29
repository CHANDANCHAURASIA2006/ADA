#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
// Bubble Sort function 
void bubbleSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (arr[j] > arr[j + 1]) { 
                // Swap arr[j] and arr[j + 1] 
                int temp = arr[j]; 
                arr[j] = arr[j + 1]; 
                arr[j + 1] = temp; 
            } 
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
    for(int i = 0; i < 100000; i++) {   // run multiples time for better measurement 
        bubbleSort(arr, n); 
    } 
    clock_t end = clock(); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 100000.0; 
    printf("Time taken to sort %d elements using Bubble Sort: %.6f seconds\n", n, time_taken); 
    free(arr); 
    return 0; 
}