#include <stdio.h>

int main() 
{
    char phoneNumber[13];
    printf("Enter phone number [(999)999-9999]: ");
    scanf("%s", phoneNumber);

    phoneNumber[0] = ' ';
    phoneNumber[4] = '-';  


    printf("You entered%s\n", phoneNumber);
    return 0; 
}