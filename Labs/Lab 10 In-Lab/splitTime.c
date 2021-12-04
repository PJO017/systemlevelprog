#include <stdio.h>

void split_time(int, int*, int*, int*);

int main(){

    int n,hr,min,sec;

    printf("Enter seconds:");
    scanf("%d",&n);


    split_time(n, &hr, &min, &sec);
    printf("Converted format: %d hour %d mins %d secs", hr, min, sec);
    
    return 0;
}
void split_time(int total_sec, int *hr, int *min, int* sec)
{ 
    int remainder;
    *hr = total_sec / 3600;
    remainder = total_sec % 3600;
    *min = remainder / 60;
    *sec = remainder % 60;

}