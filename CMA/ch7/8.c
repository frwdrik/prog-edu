#include <stdio.h>
#include <ctype.h>

#define PM_COMPENSATE 12

int main(void)
{
    // Flight departure time
    // since midnigth
    int time_closest, a = 480, b = 585, c = 689, d = 767, e = 840;       

    // Flight arrival times
    // since midnigth
    int time_arrival, a1 = 616, b1 = 712, c1 = 811, d1 = 900,  e1 = 968;

    
    // Get time form user
    int hours, minutes, time, ch; 

    printf("Enter a 12-hour time: ");
    scanf("%d:%d", &hours, &minutes);
    while (getchar() == ' ')
	;
    while ((ch = getchar()) != '\n') {
	switch (toupper(ch)) {
	case 'P':
	    if (toupper(getchar()) == 'M' || getchar() == '\n')
		time  = 60 * hours + minutes + PM_COMPENSATE;
	    break;
	case 'A':
	    if (toupper(getchar()) == 'M' || getchar() == '\n')
		time  = 60 * hours + minutes;
	    break;
	default: break; /* No default value for time since we assume
			   that the input will be either in AM or PM */
	}
    }	    

    // Find closest departure time
    if (time < a || time < (a + b) / 2) {
	time_closest = a; time_arrival = a1;
    } else if (time < (b + c) / 2) {
	time_closest = b; time_arrival = b1;
    } else if (time < (c + d) / 2) {
	time_closest = c; time_arrival = c1;
    } else if (time < (d + e) / 2) {
	time_closest = d; time_arrival = d1;
    } else {
	time_closest = e; time_arrival = e1;
    }

    // Print departure and arrival time
    printf("Closest departure time is %.2d:%.2d ", time_closest / 60, time_closest % 60);
    if (time_closest / 60 < 12)
	printf("a.m.");
    else
	printf("p.m");

    printf(", arriving at %.2d:%.2d ", e1 / 60, e1 % 60);
    if (time_arrival / 60 < 12)
	printf("a.m.\n");
    else
	printf("p.m\n");

    return 0;
}
