//linear serach//

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
 
int linearSearch(int arr[], int n, int key) { 
    for (int i = 0; i < n; i++) { 
        if (arr[i] == key) { 
            return i; 
        } 
    } 
    return -1; 
} 
 
int main() { 
    int n; 
    int *arr; 
    int key_to_search; 
    int search_result; 
 
    clock_t start_time, end_time; 
    double cpu_time_used; 
 
    printf("Enter the number of elements for the array: "); 
    scanf("%d", &n); 
 
    arr = (int*)malloc(n * sizeof(int)); 
 
    if (arr == NULL) { 
        printf("Error: Memory allocation failed.\n"); 
        return 1; 
    } 
 
    srand(time(NULL)); 
 
    printf("Generating %d random elements...\n", n); 
    for (int i = 0; i < n; i++) { 
        arr[i] = rand() % 10000; 
    } 
    printf("Array generated successfully.\n\n"); 
 
    key_to_search = -1; 
    printf("Performing linear search for key: %d (worst-case scenario)\n", key_to_search); 
 
    start_time = clock(); 
    search_result = linearSearch(arr, n, key_to_search); 
    end_time = clock(); 
 
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; 
 
    if (search_result != -1) { 
        printf("Element found at index: %d\n", search_result); 
    } else { 
        printf("Element not found in the array.\n"); 
    } 
 
    printf("Time taken for linear search: %f seconds\n", cpu_time_used); 
 
    free(arr); 
 
    return 0; 

} 
