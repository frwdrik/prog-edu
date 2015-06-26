#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


/* Gives us the difficulty of the hardest
   trip from one attraction to another */

void initializer(int x, int y, int m, int n, int *S, long *L);

/* Only defined for adjacent tiles */
long w(int x1, int y1, int x2, int y2, int m, int n, long *tiles);

/* Returns coordinates to tile with smallest
   heigth difference, and the difference itself */
long * get_minimal(int row, int col, int m, int n, long *tiles, int *S);

void djikstras(int x, int y, int m, int n, long *tiles, long *L);



int main(void)
{
    int m, n;
    int i, j;

    scanf("%d %d", &m, &n);
    
    long * L = new long[m*n];
    long * rating = new long[m*n];
    long * tiles = new long[m*n];
		  
    /* rating for each tile. Our answer
       is the largest value in this array. */
    
    for (i = 0; i < m; i++)
    	for (j = 0; j < n; j++)
    	    scanf("%ld", &tiles[n*i+j]);
    
    /* Controls which tiles are attractions */
    int att, attraction[m][n];
    for (i = 0; i < m; i++)
    	for (j = 0; j < n; j++) {
    	    scanf("%d", &att);
    	    if (att) attraction[i][j] = true;
    	    else attraction[i][j] = false;
    	}

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

    int a, b;
    long maks;
    for (i = 0; i < m; i++) 
    	for (j = 0; j < n; j++) {
	    maks = -1;
    	    if (attraction[i][j]) {
    		djikstras(i, j, m, n, tiles, L);
		for (a = 0; a < m; a++)
		    for(b = 0; b < n; b++)
			if (attraction[a][b])
			    if (L[n*a+b] > maks)
			        maks = L[n*a+b];
	    }
	    rating[n*i+j] = maks;
	}

    maks = -1;
    for (i = 0; i < m; i++) {
    	for (j = 0; j < n; j++)
	    if (rating[n*i+j] > 0 && rating[n*i+j] > maks)
		maks = rating[n*i+j];
    }

    printf("%ld", maks);
	    
    return 0;
}









void djikstras(int x, int y, int m, int n, long *tiles, long *L)
{
    
    // int m = 3, n = 4; /* Debug values, must equal array size */
    // int row=1, col=0; 
    // long tiles[3][4] = {{0, 0, 1, 100},
    //			   {1, 20, 80, 0},
    //                     {1, 1, 0, 1}};
			
/* Contains the difficulty of the trip from a chosen tile to any other tile */
    int * S = new int[m*n];   /* A cell contains "true" if the corresponding tile
		     is in the list. Otherwise, it contains "false" */
    initializer(x, y, m, n, S, L);
    long *p = 0;
    bool done = false; /* Used to test if we have added all tiles to S */
    while (!done) {
	done = true; /* Will be changed at the end if we are not done */
	int i, j;
	int t[5], min = 9999;

	/* Update the distance of all tiles not in S */
	for (i = 0; i < m; i++)
	    for (j = 0; j < n; j++) {
		if (!S[n*i+j])
		    L[n*+j] = -1;
	    }
		
	    /* 	if (!S[i][j] && (t[2] + w(t[0], t[1], i, j, m, n, tiles) < L[i][j])) */
	    /* 	    L[i][j] = t[2] + w(t[0], t[1], i, j, m, n, tiles); */
	    /* } */
        
	/* Find the tile not in S with minimal distance from a tile in S */
	for (i = 0; i < m; i++)
	    for (j = 0; j < n; j++)
		if (S[n*i+j]) {
		    p = get_minimal(i, j, m, n, tiles, S);
		    if (p[2] + L[n*+j] <= min) {
			t[0] = p[0];
			t[1] = p[1];
			t[2] = p[2];
			t[3] = i;
			t[4] = j;
			min = (t[2] < 999999 && t[2] > L[n*i+j] ? t[2] : L[n*+j]);
			/* min is now the distance from S to t[0],t[1] */
		    }
		}
	/* We add our new tile to S, and update its distance if necessary */
	S[n*t[0]+t[1]] = true;
	// if (t[2] < L[t[0]][t[1]])
	    L[n*t[0]+t[1]] = min; //+ L[t[3]][t[4]];	
	
	/* If S doesn't contain all tiles, we continue the process */
	for (i = 0; i < m; i++)
	    for (j = 0; j < n; j++)
		if (!S[n*i+j])
		    done = false;
    }
    
    
    /* int i, j; */

    /* printf("\n"); */
    /* for (i = 0; i < m; i++) { */
    /* 	for (j = 0; j < n; j++) */
    /* 	    printf("%ld ", L[i][j]); */
    /* 	printf("\n"); */
    /* } */
    
}

void initializer(int x, int y, int m, int n, int *S, long *L)
{
    int i, j;

    for (i = 0; i < m; i++)
	for (j = 0; j < n; j++) {
	    L[n*i+j] = 99;
	    S[n*i+j] = 0;
	}
    L[n*x+y] = 0;
    S[n*x+y] = 1;
}

long w(int row1, int col1, int row2, int col2, int m, int n, long *tiles)
{
    long result = LONG_MAX;
    if ((abs(row1 - row2) + abs(col1 - col2)) <= 1)
	result = abs(tiles[n*row1+col1] - tiles[n*row2+col2]);
    
	return result;
}

long * get_minimal(int row, int col, int m, int n, long *tiles, int *S)
{
    static long coord[3] = {-1, -1, LONG_MAX};
    long min = LONG_MAX - 1;
    
    /* Holds height difference to adjacent tiles */
    long up = LONG_MAX, down = LONG_MAX,
	left = LONG_MAX, rigth = LONG_MAX;
    
    /* Check if adjacent vertice is legal and not already in S */
    // up
    if (row > 0 && !S[n*(row-1)+col]) {
	up = w(row, col, row-1, col, m, n, tiles);
	min = up;
    }
    // down
    if (row < m-1 && !S[n*(row+1) +col]) {
	down = w(row, col, row+1, col, m, n, tiles);
	min = down;
    }
    // left
    if (col > 0 && !S[n*(row) +col-1]) {
	left = w(row, col, row, col-1, m, n, tiles);
	min = left;
    }
    // rigth
    if (col < n-1 && !S[n*(row)+col+1]) {
	rigth = w(row, col, row, col+1, m, n, tiles);
	min = rigth;
    }
    
    
    if (up < min) min = up;
    if (down < min) min = down;
    if (left < min) min = left;
    if (rigth < min) min = rigth;

    if (up == min) {
	coord[0] = row - 1;
	coord[1] = col;
    } else if (down == min) {
	coord[0] = row + 1;
	coord[1] = col;
    } else if (left == min) {
	coord[0] = row;
	coord[1] = col - 1;
    } else if (rigth == min) {
	coord[0] = row;
	coord[1] = col + 1; 
    }

    coord[2] = min;
    // printf("Tile closest to (%d,%d): (%d,%d)\n", row, col, coord[0], coord[1]);
    // printf("%l\n", coord[2]);
    
    return coord;
}



