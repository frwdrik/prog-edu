#include <stdio.h>
#include <string.h>

#define LINE_FILE printf("Line %d of file %s\n", __LINE__, __FILE__)

int main(void)
{
    LINE_FILE;
    
    return 0;
}

