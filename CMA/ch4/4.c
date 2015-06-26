#include <stdio.h>

int main(void)
{
    int d;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &d);
    printf("In octal, your number is: %d%d%d%d%d\n",(d / 8 / 8 / 8 / 8) % 8, (d / 8 / 8 / 8) % 8, (d / 8 / 8) % 8, (d / 8) % 8, d % 8);

    return 0;
}
