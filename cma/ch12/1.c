#include <stdio.h>

#define LEN 100

int main(void)
{
    char msg[LEN], *p;

    
    printf("Enter a message: ");
    
    for (p = msg; p < &msg[LEN]; p++) {
	*p = getchar();
	if (*p == '\n')
	    break;
    }

    printf("Reversal is: ");

    for (p--; p >= msg; p--)
	putchar(*p);
    putchar('\n');
	
    return 0;
}
