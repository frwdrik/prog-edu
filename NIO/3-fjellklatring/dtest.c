#include <stdio.h>
#include <stdbool.h>
#include "djikstras.h"

int main(void)
{
    const int m, n;
    int i, j;

    scanf("%d %d", &m, &n);
 
    long tiles[m][n], rating[m][n], L[m][n];
    /* rating holds the rating for each tile. 
       Our answer is the largest value in this array. */

    for (i = 0; i < m; i++)
    	for (j = 0; j < n; j++)
    	    scanf(" %ld", &tiles[i][j]);
   
    /* Stores which tiles are attractionsy */
    int att, attraction[m][n];
    for (i = 0; i < m; i++)
    	for (j = 0; j < n; j++) {
    	    scanf("%d", &att);
    	    if (att) attraction[m][n] = true;
	}

    for (i = 0; i < m; i++) {
    	for (j = 0; j < n; j++)
    	    printf("%ld ", tiles[i][j]);
    	printf("\n");
    }
    printf("\n");

    djikstras(0, 0, m, n, tiles, L);

    return 0;
}
    
    
