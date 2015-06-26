#include <stdio.h>

int large(int a[], int n)
{
    int i, largest = a[0];

    for(i = 1; i < n; i++)
	largest = a[i]>largest ? a[i] : largest;

    return largest;
}

float average(int a[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
	sum += a[i];

    return sum / (float) n;
}

int number_positives(int a[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
	a[i] > 0 ? sum++ : sum;;

    
	    
    return sum;
}

int main(void)
{
    int a[10] = {1,2,3,-35,6,7,8,9,20,-10};

    printf("The largest element in a is %d.\n", large(a,10));
    printf("The average of the elements in a is %.2f\n", average(a,10));
    printf("The number of positive elements is %d\n", number_positives(a,10));
    
    return 0;
}
