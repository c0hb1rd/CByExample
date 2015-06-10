#include <stdio.h>

int main(void)
{
	int a, b;
	
	a = 10;
	b = 20;

	a = a^b;
	
	printf("a = %d\n",a);
	b = a^b;
	printf("a = %d\n", a);
	a = a^b;
	printf("a = %d\n", a);

	printf("%d, %d\n", a, b);

	return 0;
}
