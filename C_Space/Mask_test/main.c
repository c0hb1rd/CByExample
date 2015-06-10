#include <stdio.h>

void binary(int);

int main(void)
{
	int mask = 0377;
	int test_num;

	puts("Enter a num:");
	scanf("%d", &test_num);

	while(getchar() != '\n')
		continue;

	int and = test_num & mask;
	int or = test_num | mask;
	int unor = test_num ^ mask;

	puts("And:");
	binary(and);
	puts("");

	puts("Or:");
	binary(or);
	puts("");

	puts("Unor:");
	binary(unor);
	puts("");

	puts("Press any key to quit...");
	getchar();

	return 0;
}

void binary(int num)
{
	if(num >= 2)
		binary(num / 2);
	putchar('0' + num % 2);
}
