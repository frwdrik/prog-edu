#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NUM_RATES ((int) (sizeof(value) / (sizeof(value[0]))))
#define INITIAL_BALANCE 100.00

int roll_dice(int);

int main(void)
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int *p = a, *q = &a[9], temp;

    while (p < q) {
	temp = *p;
	*p++ = *q;
	*q-- = temp;
    }

    for (p = a; p < a + 10; p++)
	printf("%d ", *p);
    
    return 0;
}
