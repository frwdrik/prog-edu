#include <stdio.h>

int main(void)
{
    int i, j; /* for-loop indices */
    float epsilon, factorial = 1; /* factorial = 1 since this will always be first factor */
    float approx = 1; /* approx = 1 since thil will always be first term of approximation */

    printf("Enter minimum size of each term: ");
    scanf("%f", &epsilon);

    for (i = 1;; i++) {
	for (j = 1, factorial = 1; j <= i; j++) {
	    factorial *=  j;
	    }

	if ((1.0f / factorial) < epsilon)
	    break;
	else
	    approx += (1.0f / factorial);
    }
    
    printf("Approximation of e: %f\n", approx);

    return 0;
}

	
    
