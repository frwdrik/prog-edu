#include <stdio.h>

int main(void)
{
    int days_in_month, starting_day, i;

    printf("Enter number of days in month: ");
    scanf("%d", &days_in_month);
    printf("Enter starting day of the week: ");
    scanf("%d", &starting_day);

    // Print any leading blanks
    for (i = 1; i < starting_day; i++)
	printf("    ");

    // Print the calendar
    for (i = 1; i <= days_in_month; i++) {
	printf("%4d", i);	   
	if ((i + starting_day - 1) % 7 == 0)
	    printf("\n");
    }
    printf("\n");
    
    return 0;
}
	

