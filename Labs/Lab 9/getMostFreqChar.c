# include <stdio.h>

int main(void)
{
    // Get file 
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    FILE *fl;
    if((fl = fopen(filename, "r")) == NULL){
        return -1;
    }

    // Map to keep track of frequencies
    int freqs[26];
    int ch;

    // Fill array with zeroes
    for (ch = 0; ch < 26; ch++)
        freqs[ch] = 0;


    int maxChar = 0;
    int maxFreq = 0;
    int freq;
    while ((ch = fgetc(fl)) != EOF) {
        
        if ('a' <= ch && ch  <= 'z')
            freq = freqs[ch - 'a']++;     
        else if ('A' <= ch && ch <= 'Z')
            freq = freqs[ch - 'A']++;

        if (freq > maxFreq)
            maxFreq = freq;
            maxChar = ch;  
   
    }

    maxFreq = freqs[maxChar - 'a'];

    printf("The most frequent letter is '%c'. It appeared %d times. \n", maxChar, maxFreq);
    
}