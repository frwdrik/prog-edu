#include <stdio.h>

#define LENGTH 4

void sort(int a[],int n);

int main(void)
{
    int i, a[LENGTH];

    printf("Enter %d numbers to be sorted: ", LENGTH);
    for (i = 0; i < LENGTH; i++)
	scanf("%d", &a[i]);

    printf("Your array: ");
    for (i = 0; i < LENGTH; i++)
	printf(" %-3d", a[i]);

    sort(a,LENGTH);

    printf ("\nSorted list:");
    for (i = 0; i < LENGTH; i++)
	printf(" %-3d", a[i]);
    printf("\n");

    return 0;
}

void sort(int a[], int n)
{
    int i, temp, pointer = 0, max = a[0];

    if (n > 0) {
	for (i = 0; i < n; i++) {
	    if (a[i] > max) {
		max = a[i];
		pointer = i;
	    }
	}

	printf("\n");
	for (i = 0; i < LENGTH; i++)
	    printf(" %-3d", a[i]);
	
	
	printf(" Last: %d, max: %d, pos max in sublist: %d\n", a[n-1], max, pointer);
	
/* Swap the largest element with the last element of the array. */
	temp = a[n-1];
	a[n - 1] = max;
	a[pointer] = temp;

	sort(a, n - 1);
    }
}
