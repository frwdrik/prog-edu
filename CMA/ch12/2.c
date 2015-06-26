#include <stdio.h>

#define LEN 100

int main(void)
{
    char msg[LEN], *p, *beginn_ptr, *end_ptr;

    
    printf("Enter a message: ");
    
    for (p = msg; p < &msg[LEN]; p++) {
	*p = getchar();
	if (*p == '\n')
	    break;
    }

    beginn_ptr = msg;
    end_ptr = p - 1;

    while (*beginn_ptr == *end_ptr) {
	beginn_ptr++;
	end_ptr--;
    }

    if (end_ptr + 1 == msg)
	printf("Palindrome\n");
    else
	printf("Not a palindrome\n");
	
    return 0;
}
