#include <stdio.h>

#define N 10

int main(void)
{

    double ident[N][N], *p;
    int count_zeros = 0, col_count = 1;

    for (p = ident[0]; p < &ident[N-1][N-1]; p++)
	if (count_zeros % N == 0) {
	    *p = 1.0;
	    count_zeros++;
	} else {
	    *p = 0.0;
	    count_zeros++;
	}
    
    for (p = ident[0]; p < &ident[N-1][N-1]; p++)
	if (col_count % (N - 1) == 0) {
	    printf("%f\n", *p);
	    col_count++;
	} else {
	    printf("%f ", *p);
	    col_count++;
	}
    
    return 0;
}
