#include <stdio.h>

#define LEN 2

int sum_two_dimensional_array(const int (*a)[LEN], int n);

int main(void)
{
    const int a[LEN][LEN] = {{2, 2}, {2, 2}};

    printf("Sum: %d\n", sum_two_dimensional_array( a, 2));
    
    return 0;
}

int sum_two_dimensional_array(const int (*a)[LEN], int n)
{
    int sum = 0, *p;

    for (p = a[0]; p < a[0] + (LEN * n) ; p++)
	sum += *p;

    return sum;
}
