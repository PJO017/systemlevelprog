#include <stdio.h>
#ifndef PROBLEM6WORDS_H
#define PROBLEM6WORDS_H

/*
  Reads file and returns number of words
*/

int getWords(char *filename) {
  // Open file 
  FILE *fp = fopen(filename, "r");

  char c;
  int count = 0;
  // Loop through whole file character by character
  for (c = getc(fp); c != EOF; c = getc(fp))

      // Increment count for each whitespace character
      if (c == ' ' || c == '\t' || c == '\n' || c == '\0') {
        count = count + 1;
      }

  // Account for the last word
  if (count > 0)
    count++;
    
  // Close the file
  fclose(fp);

  return count;
}

#endif
