#include <stdio.h>

#define ROW_SIZE 5
#define COLUMN_SIZE 5

int main(void)
{
    int array[ROW_SIZE][COLUMN_SIZE];
    int i, n, sum;
    
    for (i = 0; i < ROW_SIZE; i++) {
	printf("Enter row %d: ", i + 1);
	for (n = 0; n < COLUMN_SIZE; n++)
	    scanf("%d", &array[i][n]);
    }

    printf("\nRow totals:  ");
    for (i = 0; i < ROW_SIZE; i++) {
	sum = 0;
	for (n = 0; n < COLUMN_SIZE; n++)
	    sum += array[i][n];
	printf("%3d", sum);
    }

    printf("\nColumn totals: ");
    for (i = 0; i < COLUMN_SIZE; i++) {
	sum = 0;
	for (n = 0; n < ROW_SIZE; n++)
	    sum += array[n][i];
	printf("%-3d", sum);
    }
    printf("\n");
    
    return 0;
}

    
    
    
