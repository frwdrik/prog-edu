
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void generate_random_walk(char walk[N][N]);
void print_array(char walk[N][N]);

int main(void)
{
    char walk[N][N];

    generate_random_walk(walk);
    
    print_array(walk);

    return 0;
}
 
void generate_random_walk(char walk[N][N])
{
    int i , j;
    char letter;

    for (i = 0; i < N; i++)
	for (j = 0; j < N; j++)
	    walk[i][j] = '.';
    
    srand((unsigned) time(NULL));

    i = j = 0;
    
/* 0 is down, 1 is left, 2 is up and 3 is right */
    walk[0][0] = 'A';
    letter = 'B';
    while (letter <= 'Z') {
	 switch (rand() % 4) { 
	 case 0:
	     if ((i != N) && (walk[i + 1][j] == '.')) {
		 i++;
		 walk[i][j] = letter++;
		 printf("down ");
		 break;
	     }
	     else break;
	 case 1:
	     if ((j != 0) && (walk[i][j - 1] == '.')) {
		 --j;
		 walk[i][j] = letter++;
		 printf("left ");
		 break;
	     }
	     else break;
	 case 2:
	     if ((i != 0) && (walk[i - 1][j] == '.')) {
		 --i;
		 walk[i][j] = letter++;
		 printf("up ");
		 break;
	     }
	     else break;
	 case 3:
	     if ((j != N - 1) && (walk[i][j + 1] == '.')) {
		 j++;
		 walk[i][j] = letter++;
		 printf("rigth ");
		 break;
	     }
	     else break;
	 }
	 
	 /* Chek if we are trapped. */
	 if ( walk[i + 1][j] != '.' && walk[i][j + 1] != '.' &&
	      walk[i - 1][j] != '.' && walk[i][j - 1] != '.')
	     break;
    }
}

void print_array(char walk[N][N])
{
    int i, j;
    
    printf("\n");
    
    for (i = 0; i < N; i++) {
	 for (j = 0; j < N; j++)
	     printf("%-3c", walk[i][j]);
	 printf("\n");
     }
}
