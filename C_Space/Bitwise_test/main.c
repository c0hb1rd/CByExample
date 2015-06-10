#include <stdio.h>

int getInt();
int mask(int, int);
void swap(const int, int *, int *);

int main(void)
{
	int num_1 = getInt(), num_2 = getInt();

	int (* fp)(int, int);
	fp = mask;

	const int MASK = (*fp)(num_1, num_2);
	printf("num_1 = %d, num_2 = %d, MASK = %d\n", num_1, num_2, MASK);
	
	swap(MASK, &num_1, &num_2);
	printf("num_1 = %d, num_2 = %d, MASK = %d\n", num_1, num_2, MASK);

	return 0;
}

int mask(int num_1, int num_2)
{
	int mask = num_1 ^ num_2;

	return mask;
}

void swap(const int mask, int * n1, int * n2)
{
	*n1 ^= mask;
	*n2 ^= mask;
}

int getInt()
{
	int num;

	while(scanf("%d", &num) != 1) {
		puts("Error:Only accpet a interger, enter again.");
		while(getchar() != '\n')
			continue;
	}

	return num;
}
