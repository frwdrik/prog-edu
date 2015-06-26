/* Exercise a) and b) */
struct {double real, imaginary;
	} c1, c2, c3;

struct {double real, double imaginary;
	} c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

/* Exercise c) and d) */
c1 = c2;

c3.real = c1.real + c2.real;
c3.complex = c2.complex + c2.complex;
