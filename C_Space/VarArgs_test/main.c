#include <stdio.h>
#include <stdarg.h>

/* macro */
#define PD(X) printf("return value for " #X ": %g\n", X)

/* statement function */
double sum(int, ...);

int main(void)
{
	double ft, sd;

	ft = sum(4, 1.1, 2.2, 3.3, 4.4);
	sd = sum(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);

	/* print in screen */
	PD(ft);
	PD(sd);

	return 0;
}

double sum(int limit, ...)
{
	va_list list;
	double total = 0;
	int index;

	/* initialization list */
	va_start(list, limit);

	for (index = 0; index < limit; index++) {
		total += va_arg(list, double);	//interview variables
	}
	
	/* clear memory */
	va_end(list);
	return total;
}
