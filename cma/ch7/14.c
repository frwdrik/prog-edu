#include <stdio.h>
#include <math.h>

int main(void)
{
    double n, x, y, avg;

    printf("Enter a positive number: ");
    scanf("%lf", &n);

    y = 1;
    x = n;
    avg = (y + (x / y)) / 2;

    while (fabs(avg - y) > 0.000001) {
	y = avg;
	avg = (y + (x / y)) / 2;
    }

    printf("Square root: %lf\n", y);

    return 0;
}
