#include <stdio.h>

typedef struct {
    int hours, minutes, seconds;
	} Time;

Time split_time(long total_seconds);

int main(void)
{
    Time time;
    int seconds;

    printf("Enter seconds: ");
    scanf("%d", &seconds);

    time = split_time(seconds);

    printf("Hours: %d\nMinutes: %d\nSeconds: %d\n", time.hours, time.minutes, time.seconds);

    return 0;
}

Time split_time(long total_seconds)
{
    int h, m, s;

    long sec_since_midnigth = total_seconds % (3600 * 24); 

    h = sec_since_midnigth / 3600;
    m = (sec_since_midnigth - 3600 * h) / 60;
    s = sec_since_midnigth - (h * 3600) - (m * 60);

    return (Time) {h, m, s};
}
