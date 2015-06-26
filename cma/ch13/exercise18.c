#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void remove_filename(char *url)
{   
    while (*url)
        url++;
    while (*url != '/')
	--url;
    *url = '\0';
}

int main(void)
{
    char url[] = "http://www.softis.com/start.htm";

    remove_filename(url);
    printf("%s\n", url);

    return 0;
}
