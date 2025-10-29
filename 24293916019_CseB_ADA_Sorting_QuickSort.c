#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
// Partition function for Quick Sort 
int partition(int arr[], int low, int high) { 
    int pivot = arr[high];   
    int i = low - 1; 
    for (int j = low; j < high; j++) { 
        if (arr[j] <= pivot) { 
            i++; 
            // swap arr[i] and arr[j] 
            int temp = arr[i]; 
            arr[i] = arr[j]; 
            arr[j] = temp; 
        } 
    } 
    // place pivot at correct position 
    int temp = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = temp; 
 
    return (i + 1); 
} 
 
// Quick Sort function 
void quickSort(int arr[], int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);   
        quickSort(arr, pi + 1, high);  
    } 
} 
 
// Generate random array 
void generateRandomArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) { 
        arr[i] = rand() % 1000;  
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
    for (int i = 0; i < 1000; i++) { 
        quickSort(arr, 0, n - 1); 
    } 
    clock_t end = clock(); 
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0; 
    printf("Time taken to sort %d elements using Quick Sort: %.12f seconds\n", n, time_taken); 
    free(arr); 
    return 0; 
}