#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(void)
{
    int i = 0, j = 0;
    char letter;
    char a[N][N] = {{'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'},
		    {'.','.','.','.','.','.','.','.','.','.'}};
    
    

    srand((unsigned) time(NULL));
   
/* 0 is down, 1 is left, 2 is up and 3 is right */
    a[0][0] = 'A';
    letter = 'A';
    while (letter < 'Z') {
	 switch (rand() % 4) { 
	 case 0:
	     if ((i != N) && (a[i + 1][j] == '.')) {
		 i++;
		 a[i][j] = ++letter;
		 printf("down ");
		 break;
	     }
	     else break;
	 case 1:
	     if ((j != 0) && (a[i][j - 1] == '.')) {
		 --j;
		 a[i][j] = ++letter;
		 printf("left ");
		 break;
	     }
	     else break;
	 case 2:
	     if ((i != 0) && (a[i - 1][j] == '.')) {
		 --i;
		 a[i][j] = ++letter;
		 printf("up ");
		 break;
	     }
	     else break;
	 case 3:
	     if ((j != N - 1) && (a[i][j + 1] == '.')) {
		 j++;
		 a[i][j] = ++letter;
		 printf("rigth ");
		 break;
	     }
	     else break;
	 }
	 /* Check if we are trapped. */
	 if ( a[i + 1][j] != '.' && a[i][j + 1] != '.' && 
	      a[i - 1][j] != '.' && a[i][j - 1] != '.')
	     break;
    }
    printf("\n");


/* Print loop */

     for (i = 0; i < N; i++) {
	 for (j = 0; j < N; j++)
	     printf("%-3c", a[i][j]);
	 printf("\n");
     }
    
     return 0;
}

