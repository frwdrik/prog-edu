#include <stdio.h>

int main(void)
{
    int number;

    printf("Enter number to be reversed: ");
    scanf("%d", &number);
    
    printf("Your number reversed is: ");
    for (; number > 0; number /= 10)
	printf("%d", number % 10);

    printf(".\n");

    return 0;
}
