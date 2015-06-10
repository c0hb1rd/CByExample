#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* macro */
#define NUM 40 
#define PN(X) printf("%d\t", X)

/* statement function */
void getAry(int *, int);
void showAry(const int *, int n);

int main(void)
{
	int nums[NUM];
	static int duplicate[NUM];
	
	/* show source list */
	puts("Source list: ");
	getAry(nums, NUM);
	showAry(nums, NUM);

	/* show duplicate list */
	puts("Duplicate list:");
	memmove(duplicate, nums, NUM * sizeof(int));
	showAry(duplicate, NUM);

	return 0;
}

void getAry(int nums[], int n)
{
	int index;
	for (index = 0; index < n; index++) {
		nums[index] = rand() % 100;
	}
}

void showAry(const int nums[], int n)
{
	int index;
	for (index = 0; index < n; index++) {
		PN(nums[index]);
		if (5 == index % 6)
			puts("");
	}

	if (0 != index % 6)
		puts("");
}
