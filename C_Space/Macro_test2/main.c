#include <stdio.h>

/* macro */
#define PF(...) printf(__VA_ARGS__)
#define MAX(X, Y) ((X) > (Y)? (X) : (Y))
#define ABS(X) ((X) < 0 ? -(X) : (X))

int main(void)
{
	PF("This is a test.\n");
	int num_1 = 10;
	int num_2 = 20;

	PF("Max is : %d\n", MAX(num_1, num_2));

	return 0;
}
