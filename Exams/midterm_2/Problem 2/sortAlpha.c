#include <stdio.h>
#include <string.h>

void swap(char strings[8][12], int i, int j) {
  char temp[12];  
  strcpy(temp, strings[i]);     // Temp variable to hold string 1
  strcpy(strings[i], strings[j]);   // Swap string 1 with string 2
  strcpy(strings[j], temp);   // Swap string 2 with string 1 stored in temp
}

void sort_alphabetic(char strings[8][12], int n, char option) {
  // Iterate through array of strings
  int i, j;
   for (i = 0; i < n - 1 ; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                // Compare strings and swap if needed
                if (strcmp(strings[i], strings[j]) > 0 && (option == 'A' || option == 'a')) {
                  swap(strings, i, j);
                }

                // Compare strings and swap if needed
                if (strcmp(strings[j], strings[i]) > 0 && (option == 'D' || option == 'd')) {
                  swap(strings, j, i);
                }
                  
            }
        }
}

// Function to print the strings
void printStrings(char strings[8][12]) {
  for (int i = 0; i < 8; i++) {
    printf("%s \n", &strings[i][0]);
  }
  printf("\n");
}

int main() {
  // Array of strings
  char strings[8][12] = {
    "System",
    "Programming",
    "Deep",
    "Learning",
    "Internet",
    "Things",
    "Robotics",
    "Course"
  };

  // Get user input ascending or descending
  char option;
  printf("(A)scending or (D)esceding Order: ");
  scanf("%c", &option);

  printf("Before sort: \n");
  printStrings(strings);
  
  // Sort array of strings
  sort_alphabetic(strings, 8, option);

  printf("After sort: \n");
  printStrings(strings);

  return 0;
}