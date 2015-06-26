#include <stdio.h>

int strcmp(char *s, char *t)
{
    for(; *s == *t; s++, t++)
	if (*s == '\0')
	    return 0;
    return *s - *t;
}

int main(void)
{
    char *s = "Look there";
    char *t = "Look here";

    printf("%d\n", strcmp(s, t));

    return 0;
}
