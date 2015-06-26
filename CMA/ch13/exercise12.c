#include <stdio.h>
#include <string.h>

void get_extension(const char *file_name, char *extension)
{
    // extension[0] = '\0';
    
    while (*file_name++ != '.' && *file_name)
	; /* gets a pointer to beginning of the extension */
    if (*(--file_name) == '.')
	strcpy(extension, ++file_name);
}


int main(void)
{
    char file_name[100];
    char ext[10];

    printf("Enter file name (with extension): ");
    scanf("%s", file_name);
    
    get_extension(file_name, ext);

    printf("File extension of %s: %s\n", file_name, ext);
    
    return 0;
}
