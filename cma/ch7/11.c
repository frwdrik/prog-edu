/* This code uses getchar and putchar instead
 *  scanf and printf. It allows multiple surnames
 *  and capitalizes the first initial.
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch, initial;

    printf("Enter a first and last name: ");

    do {
	initial = (toupper(getchar()));
    } while (getchar() == ' '); /* Ignore extra spaces 
				   before first name. */

    while (getchar() != ' ') /* Ignore remaining characters */
	;                    /* in first name               */ 
    
    while ((ch = getchar()) == ' ') /* Ignore extra spaces */
	;			    /* before last name    */
    
    putchar(ch); /* Print the first non-space character */
    
    while ((ch = getchar()) != '\n')
	    putchar(ch);
    
    printf(", %c.\n", initial);

    return 0;
}
