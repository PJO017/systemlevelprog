#include <stdio.h>
#ifndef PROBLEM6LINES_H
#define PROBLEM6LINES_H

/*
  Reads file and returns number of lines
*/

int getLines(char *filename) {
  // Open file 
  FILE *fp = fopen(filename, "r");

  char c;
  int count = 0;
  // Loop through whole file character by character
  for (c = getc(fp); c != EOF; c = getc(fp)) {

      // If at least one character add one to line
      if (count == 0) {
        count++;
      }
        
      // Increment count for new line character
      if (c == '\n') {
        count++;        
      }

  }
  
  // Close the file
  fclose(fp);

  return count;
}

#endif
