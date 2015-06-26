#include <stdio.h>
#include <stdbool.h>

struct Reise {
    int fra;
    int til;
    int pos;
};

long togstasjoner;
int reisende;

void quicksort(struct Reise a[], int low, int high);
int split(struct Reise a[], int low, int high);

int main(void)
{
    int i, j, result, a[4];
    
    /* Holder orden på hvor de reisende skal, og
       hvor mange billetter de har til enhver tid */
    scanf("%lf %d", &togstasjoner, &reisende);
    struct Reise reiser[reisende];
    bool har_billett[reisende];
    for (i = 0; i < reisende; i++) {
	scanf("%d %d", &reiser[i].fra, &reiser[i].til);
	reiser[i].pos = reiser[i].fra;
    }

    /* Sorterer arrayet med reisende i stigende rekkefølge
       etter hvilken stasjon de reiser fra */
    quicksort(reiser, 0, reisende - 1);

/*  printf("Fra: \t Til:\n");
 *  for (i = 0; i < reisende; i++)
 *   printf("%d \t  %d\n", reiser[i].fra, reiser[i].til);
 */
    int billetter;
    for (j = 0; j < reisende; j++) {
	billetter = j + 1;
        har_billett[0] = true;
	billetter--;

	for (i = 0; i < reisende; i++) {
	    if (har_billett[i]) {
		/* Hvis noen går av på samme stasjon som en
	   annen reiser fra, gi påstigende billetten */
		for (j = 0; j < reisende; j++) {
		    if (reiser[i].til == reiser[j].fra) {
			har_billett[i] = false;
			reiser[i].pos = reiser[i].til;
			har_billett[j] = true;
			break;
		    }
		}
	    }
	}

	/* Hvis noen har billett, men er ikke kommet frem,
	   så reis de nå dit de skal */
	for (i = 0; i < reisende; i++)
	    if (reiser[i].pos != reiser[i].til && har_billett[i])
		reiser[i].pos = reiser[i].til;
	
	/* Tester om alle har kommet fram til sin destinasjon.
	   Hvis ikke, så trenger vi flere billetter. */
	for (i = 0; i < reisende; i++)
	    if (reiser[i].pos == reiser[i].til) {
		printf("%d\n", j);
		break; /* Printer antall billetter nødvendig */
	    } else
		continue;
    }

    return 0;
}

void quicksort(struct Reise  a[], int low, int high)
{
    int middle;

    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle-1);
    quicksort(a, middle+1, high);
}

int split(struct Reise a[], int low, int high)
{
    int part_element = a[low].fra;

    for (;;) {
	while (low < high && part_element <= a[high].fra)
	    high--;
	if (low >= high) break;
	a[low++] = a[high];

	while (low < high && a[low].fra <= part_element)
	    low++;
	if (low >= high) break;
	a[high--] = a[low];
    }

    a[high].fra = part_element;
    return high;
}
