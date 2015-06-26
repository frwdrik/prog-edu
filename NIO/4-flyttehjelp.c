#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int find_max(int n, bool a[n][n], int node, int cur_len, int prev_node);
void initialize(int n, bool a[n][n]);

int main(void)
{
    /* Get number of roads */
    int n;
    scanf("%d", &n);

    bool a[n][n];
    initialize(n, a);

    /* Store the roads in array a */
    int i, x, y;
    for(i = 1; i < n; i++) {
	scanf("%d %d", &x, &y);
	a[y][x] = a[x][y] = true;
    }
    
    int min = INT_MAX, result, node_ptr;
    for (i = 0; i < n; i++) { /* Starting node */
	result = find_max(n, a, i, 0, -1);
	if (result < min) {
	    min = result;
	    node_ptr = i;
	}
    }

    printf("%d", node_ptr);
    
    return 0;
}

void initialize(int n, bool a[n][n])
{
    int i, j;
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++)
	    a[i][j] = false;
    }
}

int find_max(int n, bool a[n][n], int node, int cur_len, int prev_node)
{
    int j, length = 0, temp = -1;
           
    for (j = 0; j < n; j++)
	if (j != prev_node) /* In order not to go backwards */
	    if (a[node][j]) {
		temp = 1 + find_max(n, a, j, cur_len+1, node);
		if (temp > length)
		    length = temp;
	    }

    return length;
}

/*   0 1 2 3 4 5 6 7 8 */
   
/* 0. 0 1 0 0 0 0 0 0 0 */
/* 1  1 0 1 0 0 0 0 0 0 */
/* 2. 0 1 0 1 1 0 1 0 0 */
/* 3. 0 0 1 0 0 0 0 0 0 */
/* 4. 0 0 1 0 0 1 0 0 0 */
/* 5. 0 0 0 0 1 0 0 0 0 */
/* 6. 0 0 1 0 0 0 0 1 1 */
/* 7. 0 0 0 0 0 0 1 0 0 */
/* 8. 0 0 0 0 0 0 1 0 0 */
