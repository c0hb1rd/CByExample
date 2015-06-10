#include <stdio.h>
#include <stdlib.h>

/* macro */
#define NUM 40
#define THE_WAY 1
#define ANTHOR_WAY 0

/* statement function */
void fillarray(double *, int n);
void showarray(const double *, int n);
int mycomp(const void *, const void *);

int main(void)
{
	/* random array */
	double vals[NUM];
	fillarray(vals, NUM);
	
	/* print random array list */
	puts("Random list: ");
	showarray(vals, NUM);

	/* sort array and print */ 
	puts("Sort list: ");
	qsort(vals, NUM, sizeof(double), mycomp);
	showarray(vals, NUM);

	return 0;
}

void fillarray(double ar[], int n)
{
	int index;

	for (index = 0; index < n; index++) {
		ar[index] = (double)rand() / ((double)rand() + 0.1);
	}
}

void showarray(const double ar[], int n)
{
	int index;

	for (index = 0; index < n; index++) {
		printf("%9.4lf\t", ar[index]);

		if (5 == index % 6)
			puts("");
	}

	if (0 != index % 6)
		puts("");
}

int mycomp(const void * p1, const void * p2)
{
	const double * a1 = (const double *)p1;
	const double * a2 = (const double *)p2;

#if THE_WAY
	if (*a1 < *a2)
		return 1;	
	else if (*a1 == *a2)
		return 0;
	else
		return -1;
#endif

#if ANTHOR_WAY
	if (*a1 > *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
#endif
}
