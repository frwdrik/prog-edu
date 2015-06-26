#include <stdio.h>

#define N 15

int main(void)
{
    
    char input, a[N] = {'\n','\n','\n','\n','\n','\n','\n','\n','\n','\n','\n','\n','\n','\n','\n'};
    int i;

    printf("Enter phone number: ");

    for (i = 0; ((input = getchar()) != '\n') && i < N; i++) {
	switch (input) {
	case 'A': case 'B': case 'C':
	    a[i] = '2'; break;
	case 'D': case 'E': case 'F':
	    a[i] = '3'; break;
	case 'G': case 'H': case 'I':
	    a[i] = '4'; break;
	case 'J': case 'K': case 'L':
	   a[i] = '5'; break;
	case 'M': case 'N': case 'O':
	   a[i] = '6'; break;
	case 'P': case 'R': case 'S':
	   a[i] = '7'; break;
	case 'T': case 'U': case 'V':
	    a[i] = '8'; break;
	case 'W': case 'X': case 'Y':
	   a[i] = '9'; break;
	default:
	    a[i] = input;
	}
    }
	
    for ( i = 0; a[i] != '\n'; i++)
	putchar(a[i]);
	    
    putchar('\n');
 
    return 0;
}
				 
				 
	
	
    
