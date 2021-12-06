#include <stdio.h>
#include <string.h>
// Include header files
#include "problem6char.h"    
#include "problem6lines.h"
#include "problem6words.h"

int main(int argc, char *argv[]) {

  // Check for argument
  if (argc < 2) {
    printf("Enter text file as argument: ./problem5output [TEXT FILE] \n");
    return 1;
  }

  // Get text file from command line argument
  char *file = argv[1];
  
  // Get number of characters, lines, and words from file
  int numOfChar = getCharacters(file);
  int numOfLines = getLines(file);
  int numOfWords = getWords(file);

  // Open data file
  FILE *fp = fopen("data.txt", "a");

  // Append data to end of file
  fprintf(fp, "Characters: %d; Lines: %d; Words: %d \n", numOfChar, numOfLines, numOfWords);

  // Close file
  fclose(fp);
  
  return 0;
}