/* Exercise a) and b) */
struct complex {double real,
	double imaginary
	};

struct complex c1, c2;

/* Exercise c) */
struct complex make_complex(double real, double imaginary)
{
    return ((struct complex) {real, imaginary});
}

/* Exercise d) */
struct add_complex(struct complex z1, struct complex z2)
{
    return (struct complex) {z1.real+z2.real, z1.imaginary+z2.imaginary}
;
}
