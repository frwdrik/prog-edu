#include <stdio.h>
#include <dijkstras.h>

int main(void)
{
    const int m, n;
    int i, j;

    scanf("%d %d", &m, &n);

    long tiles[m][n], rating[m][n];
    /* rating for each tile. Our answer
       is the largest value in this array. */
    
    for (i = 0; i < m; i++)
	for (j = 0; j < n; j++)
	    scanf("%lf", &tiles[i][j]);
    
    /* Controls which tiles are attractive */
    int att, attraction[m][n];
    for (i = 0; i < m; i++)
	for (j = 0; j < n; j++) {
	    scanf("%d", &att);
	    if (att) attraction[m][n] = true;
	}
    
    djikstras(0, 0, m, n, tiles);

    return 0;
}

    
    
