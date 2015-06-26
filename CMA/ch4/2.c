#include <stdio.h>

int main(void)
{
    int d, d1, d2, d3;

    printf("Enter a three digit number: ");
    scanf("%d", &d);

    d1 = d / 100;
    d2 = (d % 100) / 10;
    d3 = (d % 100) % 10;

    printf("The reversal is: %d%d%d", d3, d2, d1);

    return 0;
}
