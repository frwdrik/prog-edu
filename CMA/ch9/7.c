#include <stdio.h>

int power(int x, int n);

int main(void)
{
    int x, n;

    printf("Enter number and expnonent: ");
    scanf("%d %d", &x, &n);

    printf("%d\n", power(x, n));

    return 0;
}

int power(int x,int n)
{
    int result;

    if (n == 0) result = 1;    
     else if (n == 2) result = x * x;
     else if (n % 2 == 0) result = power(power(x , n / 2), 2);
    else result = x * power(x , (n - 1));
    
    return result;
}
