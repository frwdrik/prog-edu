#include <stdio.h>

float compute_GPA(char grades[], int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
	switch(grades[i]) {
	case 'A': sum+= 4; break;
	case 'B': sum+= 3; break;
	case 'C': sum+= 2; break;
	case 'D': sum++; break;
	default: break;
	}

    return (float) sum / n;
}

int main(void)
{
    char a[8] = {'A','A','A','B','C','D','E','F',};

    printf("Average: %.2f.\n", compute_GPA(a, 8));

    return 0;
}
