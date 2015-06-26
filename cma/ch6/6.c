/* Program to display all even primes
   between 1 and a chosen number. */

#include <stdio.h>

int main(void)
{
    int n, i;

    printf("Enter a limit on maximum square: ");
    scanf("%d", &n);

    for (i = 2; i * i <= n; i += 2)
	printf("%d\n", i * i);

    return 0;
}
