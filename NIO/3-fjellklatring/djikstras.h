#include <stdbool.h>

#ifndef DJIKSTRAS_H
#define DJIKSTRAS_H


void initialize(int x, int y, int m, int n, bool S[m][n], long L[2][2]);

/* Only defined for adjacent tiles */
long w(int x1, int y1, int x2, int y2, int m, int n, long tiles[m][n]);

/* Returns coordinates to tile with smallest
   heigth difference, and the difference itself */
long * get_minimal(int row, int col, int m, int n, long tiles[m][n], bool S[m][n]);

void djikstras(int x, int y, int m, int n, long tiles[m][n], long L[2][2]);

#endif

 /* printf("\nAttractions: \n"); */
    /* for (i = 0; i < m; i++) */
    /* 	for (j = 0; j < n; j++) */
    /* 	    printf("%d ", attraction[i][j]); */
    /* printf("\n\n"); */

	
    /* for (i = 0; i < m; i++) { */
    /* 	for (j = 0; j < n; j++) */
    /* 	    printf("%-4ld", tiles[i][j]); */
    /* 	printf("\n\n"); */
    /* } */

	
	    /* 	if (!S[i][j] && (t[2] + w(t[0], t[1], i, j, m, n, tiles) < L[i][j])) */
	    /* 	    L[i][j] = t[2] + w(t[0], t[1], i, j, m, n, tiles); */
	    /* } */
