# include <stdio.h>


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
 
/* Function to print an array */
void printArray(double arr[], int size)
{
    int i;
    printf("[");
    for (i=0; i < size; i++)
        printf("%f, ", arr[i]);
    printf("]\n");
}

int main()
{
    // Array to sort
    double arr[11] = {10, 0.25, -2342, 12123, 3.145435, 6, 6, 5.999, -2, -5, -109.56};

    // Get user input ascending or descending
    char option;
    printf("(A)scending or (D)esceding Order: ");
    scanf("%c", &option);

    // Print array before sort
    printf("Before sort: ");
    printArray(arr, 11);

    // Sort array
    sort_numeric(arr, 11, option);

    // Print array after sort
    printf("After sort: ");
    printArray(arr, 11);

    return 0;
}