#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *duplicate(char *string)
{
    char *p;
    p = malloc(strlen(string));
    strcpy(p, string);

    return p;
}

    
int main(void)
{
    char *str = "hei der";
    char *c = duplicate(str);

    printf("%s", c);
    
    return 0;
}

    
