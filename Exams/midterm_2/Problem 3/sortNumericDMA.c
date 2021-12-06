#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Use pointers to swap elements in array
void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}
 

// A function to implement bubble sort
void sort_numeric(double arr[], int n, char option)
{
    int i, j;
    for (i = 0; i < n-1; i++)     
        // Last i elements are already in place  
        for (j = 0; j < n-i-1; j++)

            // If the option is ascending    
            if (arr[j] > arr[j+1] && (option == 'A' || option == 'a')) {
                swap(&arr[j], &arr[j+1]);
            }
            
            // If the option is descending
            else if (arr[j] < arr[j+1] && (option == 'D' || option == 'd')) {
                swap(&arr[j], &arr[j+1]);
            }       
                
}
    
// Function to print an array 
void printArray(double arr[], int size)
{
    int i;
    printf("[");
    for (i=0; i < size; i++)
        printf("%.1f, ", arr[i]);
    printf("]\n");
    printf("\n");
}

// Function to fill array with random numbers
void fillArray(double* arr, int n)
{   int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
        arr[i] = rand() % 3000;
}

int main()
{

    // Get number of entries
    int n;
    printf("# of entries: ");
    scanf("%d", &n);

    // Allocate correct amount of memory for chosen num of elements
    double* arr;
    arr = (double*) malloc(n * sizeof(double));

    // Fill array with random numbers
    fillArray(arr, n);
    
    // Get user input ascending or descending
    char option;
    printf("(A)scending or (D)esceding Order: ");
    scanf(" %c", &option);

    // Print array before sort
    printf("Before sort: ");
    printArray(arr, n);

    // Sort array
    sort_numeric(arr, n, option);

    // Print array after sort
    printf("After sort: ");
    printArray(arr, n);


    return 0;
}