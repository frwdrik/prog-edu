#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_malloc(int bytes)
{
    void *p;
    if(p = malloc(bytes))
	return p;
    else
	exit(EXIT_FAILURE);
}

int main(void)
{
    char *c = my_malloc(10);

    return 0;
}

    
