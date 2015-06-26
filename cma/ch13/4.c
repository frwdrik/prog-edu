#include <stdio.h>
#include <string.h>

int main(int argc, char *arcv[])
{
    int i;

    for (i = argc - 1; i > 0; i--)
	printf("%s ", arcv[i]);
    printf("\n");

    return 0;
}
