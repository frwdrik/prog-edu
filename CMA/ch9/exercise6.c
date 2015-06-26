#include <stdio.h>

int digit(int n, int k)
{
    int i;

    for (i = 0; i < n, i++)
	n /= 10;
    
    return n % 10;
}
