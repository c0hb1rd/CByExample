#include <stdio.h>
#include <stdlib.h>

/* statement function */
void test1();
void test2();

int main(void)
{
	atexit(test1);
	atexit(test2);

	exit(EXIT_FAILURE);

	return 0;
}

void test1()
{
	puts("Frist test.");
}

void test2()
{
	puts("Second test.");
}
