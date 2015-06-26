#include <stdio.h>

#define ROW_SIZE 8
#define COLUMN_SIZE 8

int main(void)
{
    char checker_board[ROW_SIZE][COLUMN_SIZE];
    int i, j;

    for (i = 0; i < ROW_SIZE; i++) {
	for (j = 0; j < COLUMN_SIZE; j++) {
	    if ((j + i) % 2 == 0)
		checker_board[i][j] = 'B';
	    else
		checker_board[i][j] = 'R';
	}
    }

    for (i = 0; i < ROW_SIZE; i++) {
	for (j = 0; j < COLUMN_SIZE; j++) {
	    printf("%-3c", checker_board[i][j]);
	}
	printf("\n");
    }

    return 0;
}
