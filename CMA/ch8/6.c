#include <ctype.h>
#include <stdio.h>

#define MSG_LENGTH 50
int main(void)
{
    char ch, message[MSG_LENGTH];
    int i, n;

    printf("Enter message: ");

    for (i = 0; i < MSG_LENGTH; i++) {
	if ((ch = getchar()) == '\n') {
	    message[i] = ch;
	    break;
	}
	(message[i] = toupper(ch));
    }

    printf("In B1FF-speak: ");

    for (i = 0; (ch = message[i]) != '\n'; i++) {
	switch (ch) {
	case 'A': ch = '4'; break;
	case 'B': ch = '8'; break;
	case 'E': ch = '3'; break;
	case 'I': ch = '1'; break;
	case 'O': ch = '0'; break;
	case 'S': ch = '5'; break;
	default: break;
	}
	putchar(ch);
    }
    printf("!!!!!!!!\n");

    return 0;
}

       
