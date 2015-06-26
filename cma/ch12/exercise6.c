int sum_array(const int *a, int n)
{
    int sum = 0, *p = NULL;

    for (p = a; p < a + n; p++)
	sum += *p;
    return sum;
}
