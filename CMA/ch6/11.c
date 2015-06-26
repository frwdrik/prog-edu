#include <stdio.h>

int main(void)
{
    int n, i, j;
    float approx = 1, factorial = 1; /* approx = 1 since this will always be first term */

    printf("Enter number of approximating terms: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
	for (j = 1, factorial = 1; j <= i; j++)
	    factorial *=  j;
    	approx += (1 / factorial);
    }

    printf("Approximation of e: %f\n", approx);

    return 0;
}

	
    
