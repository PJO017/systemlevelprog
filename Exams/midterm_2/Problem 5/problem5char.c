#include <stdio.h>

int getCharacters(char *filename) {
  // Open file
  FILE *fp = fopen(filename, "r");

  char c;
  int count = 0;
  // Loop through whole file character by character
  for (c = getc(fp); c != EOF; c = getc(fp))

      // Increment count for each character
      count = count + 1;

  // Close the file
  fclose(fp);

  return count;
}
