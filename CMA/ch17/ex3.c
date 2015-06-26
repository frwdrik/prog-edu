#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE  12
int *create_array(int n, int initial_value)
{
    int *a = malloc(n * sizeof(int)); 
    if (a != NULL) {
	int i;
	for (i = 0; i < n; i++)
	    a[i] = initial_value; 
	return a;
    } else
	return NULL;
}

int main(void)
{

    int *array;
    array = create_array(ARRAY_SIZE, 7);
    int i;
    for (i = 0; i < ARRAY_SIZE; i++)
	printf("%d ", array[i]);
    
    return 0;
}
