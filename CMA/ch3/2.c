#include <stdio.h>

int main(void)
{
    int item, dd, mm, yyyy;
    float price;

    printf("Enter item number: ");
    scanf("%d", &item);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &dd,&mm,&yyyy);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%d\t\t$%8.2f\t%d/%d/%d\n", item, price, dd, mm, yyyy);

    return 0;
}
