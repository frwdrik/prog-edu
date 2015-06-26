#include <stdio.h>
#include <string.h>

#define DISP(f,x) printf(#f "(%g) = %g\n", x , f(x))

int main(int argc, char *arcv[])
{
    DISP(sqrt, 3.0);
    
    return 0;
}

