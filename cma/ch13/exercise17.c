#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool test_extension(const char *file_name, const char *extension)
{   
    while (*file_name)
        file_name++;
    while(*extension)
	extension++;

    while (*file_name != '.')
	if (toupper(*file_name--) != toupper(*extension--))
	    return false;
    return true;    
}

int main(void)
{
    char f[] = "domy.jpg";
    char ext[] = "JPG";
    
    printf("%d\n", test_extension(f,ext));

    return 0;
}
