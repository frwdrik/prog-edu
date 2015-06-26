#include <stdio.h>
#include <string.h>

#define MEDIAN(x,y,z) ((x) < (y) && (x) < (z) ? \
		       ((y) < (z) ? (y) : (z)) : ((x) < (y) ? (y) : ((x) < (z) ? (x) : (z))))

int main(int argc, char **argv)
{
    printf("The median is %d\n", MEDIAN(3,10,9));
    
    return 0;
}

