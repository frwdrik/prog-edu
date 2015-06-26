#include <stdio.h>

int main(void)
{
    float f, max = 0.0f;
    
    do {
	printf("Enter a number: ");
	scanf("%f", &f);
	if (f > max)
	    max = f;
    } while (f > 0);

    printf("\nThe largest number entered was %.2f.\n", max);

    return 0;
}
    
