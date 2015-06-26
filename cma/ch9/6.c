#include <stdio.h>

int polynomial(int x);

int main(void)
{
    int x;

    printf("Enter a value for x: ");
    scanf("%d", &x);

    printf("%d\n", polynomial(x));

    

    return 0;
}

int polynomial(int x)
{
    int result;

    result = (x - 1) * (3 * x * x * x * x + 5 * x * x * x - x + 6);

    return result;
}
