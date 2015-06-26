#include <stdio.h>

typedef struct{
    int day, month, year;
} Date;

int day_of_year(Date d);
int compare_dates(Date d1, Date d2);

int main(void)
{
    Date d1, d2;

    printf("Enter first date (day/month/year): ");
    scanf("%d /%d /%d", &d1.day, &d1.month, &d1.year);
    printf("Enter second date (day/month/year): ");
    scanf("%d /%d /%d", &d2.day, &d2.month, &d2.year);

    if (compare_dates(d1, d2) < 0)
	printf("The first date comes earliest\n");
    else if (compare_dates(d1, d2) > 0)
	printf("The second date comes earliest\n");
    else
	printf("The dates are the same\n");

    return 0;
}

int day_of_year(Date d)
{
    int num_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_count = 0, i;

    for (i = 1; i < d.month; i++)
	day_count += num_days[i-1];

    if (d.year % 4 == 0 && (d.year % 100 == 0 || d.year % 400 == 0))
	day_count++;

    return day_count + d.day;
}

int compare_dates(Date d1, Date d2)
{
    if (day_of_year(d1) < day_of_year(d2))
	return -1;
    else if (day_of_year(d1) > day_of_year(d2))
	return 1;
    else
	return 0;
}
