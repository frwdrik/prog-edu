#include <stdio.h>
#include <stdbool.h>

bool search(const int *a, int n, int key);

int main(void)
{
    int a[4] = {33, 28, 49, 28};

    if (search(a, 4, 28))
	printf("Found\n");
    else
	printf("Not found\n");

    return 0;
}
	

bool search(const int *a, int n, int key)
{
    int *p = NULL;

    for (p = a; p < a + n; p++)
    {
	if (*p == key)
	    return true;
    }
    return false;
}
