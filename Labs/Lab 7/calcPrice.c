#include <stdio.h>

int main()
{
    int itemNum;
    double unitPrice;
    int quantity;
    double total;
    char purchaseDate[10];


    printf("Enter item number: ");
    scanf("%d", &itemNum);

    printf("Enter unit price: ");
    scanf("%lf", &unitPrice);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter purchase date: ");
    scanf("%s", purchaseDate);


    total = unitPrice * quantity;

    printf("ITEM         UNIT PRICE    QTY   PURCHASE DATE    TOTAL AMOUNT\n");
    printf("%-4d         $%-10lf    %-3d   %-13s    $%-lf\n", itemNum, unitPrice, quantity, purchaseDate, total);
} 