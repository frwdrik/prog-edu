#include <stdio.h>

#define N 200

int main(void)
{
    char end_char = ' ', a[N] = {[0 ... N-1] = '\n'};
    int i, n, effective_size = N;

    printf("Enter a sentence: ");

    for (i = 0; i < N; i++) {
	a[i] = getchar();

	switch(a[i]) {  // End if input is a terminating character
	case '.': case '!': case '?':
	    end_char = a[i];
	    effective_size = i - 1;	    
	    break;
	default: break;
	}
        // Add sentinel and break loop when end_char is set.	    
	if (end_char != ' ') { 
	    a[i] = '\n'; 
	    break;
	}
    }

    printf("Reversal of sentence:");

    for (i = effective_size; i >=0; --i) {
	if (a[i] == ' ') {
	    putchar(' ');
	    for (n = i + 1; (a[n] != '\n') && (a[n] != ' '); n++)
		putchar(a[n]);
	}

	if (i == 0) {
	    putchar(' ');
	    for (n = 0; a[n] != ' '; n++)
		putchar(a[n]);
	    break;
	}
    }

    printf("%c\n", end_char);

    return 0;
}

			   
