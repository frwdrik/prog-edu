#include <stdio.h>

int main(void)
{
/* Exercise a) and b) */
    typedef struct {
	double real, imaginary;
    } Complex;

    Complex c1, c2, c3;

/* Exercise d) */
    Complex add_complex(Complex z1, Complex z2)
    {
	return (Complex) {z1.real+z2.real, z1.imaginary+z2.imaginary};
    }

    Complex z1 = {1.0, -1.0}, z2 = {5.3, 9.4};
    c3 = add_complex(z1, z2);
    
    printf("Real: %lf\nImaginary: %lf\n", c3.real, c3.imaginary);

    return 0;
}
