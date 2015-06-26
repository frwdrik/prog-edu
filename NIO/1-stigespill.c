#include <stdio.h>

int main(void)
{
    struct Stige {
	int src;
	int dst;
    };
    
    int antall_stiger, antall_terningkast, i, j;
    int pos_martin = 1, pos_lise = 1;

    scanf("%d %d", &antall_stiger, &antall_terningkast);

    /* Array for å holde orden på stigene, hvilken rute
       de fører fra og hvilken rute de fører til */
    struct Stige stiger[antall_stiger];
    for (i = 0; i < antall_stiger; i++)
	scanf("%d %d", &stiger[i].src, &stiger[i].dst);

    /* Array for å holde orden på terningkastene */
    int terningkast[antall_terningkast];
    for (i = 0; i < antall_terningkast; i++)
	scanf("%d", &terningkast[i]);

    /* Selve simuleringen av spillet */
    for (i = 0; (2 * i) < antall_terningkast; i++) {
	/* Oppaterer posisjonen til Martin */
	pos_martin += terningkast[2*i];
	if (pos_martin >= 100) {
	    printf("Martin %d %d\n", i+1, pos_lise);
	    return 0;
	};
	for (j = 0; j < antall_stiger; j++)
	    if (stiger[j].src == pos_martin)
		pos_martin = stiger[j].dst;
	

	/* Oppaterer posisjonen til Lise hvis
	   det er flere terningkast igjen */
	if ((2 * i) + 1 < antall_terningkast) {
	    pos_lise += terningkast[(2*i)+1];
	    if (pos_lise >= 100) {
		printf("Lise %d %d\n", i+1, pos_martin);
		return 0;
	    }
		for (j = 0; j < antall_stiger; j++)
		    if (stiger[j].src == pos_lise)
			pos_lise = stiger[j].dst;
	}
    }
    
    printf("%d %d\n", pos_martin, pos_lise);
    
    return 0;
}
