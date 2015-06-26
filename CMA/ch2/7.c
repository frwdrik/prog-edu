#include <stdio.h>

int main(void)
{
    int amount, bill20, bill10, bill5, bill1;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    bill20 = amount / 20;
    bill10 = (amount - 20 * bill20) / 10;
    bill5 = (amount - 20 * bill20 - 10 * bill10) / 5;
    bill1 = (amount - 20 * bill20 - 10 * bill10 - 5 * bill5);

    printf("$20 bills: %d\n", bill20);
    printf("$10 bills: %d\n", bill10);
    printf("$5 bills: %d\n", bill5);
    printf("$1 bills: %d\n", bill1);
    
    return 0;
}
