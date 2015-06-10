#include <stdio.h>

int main(void)
{
	printf("Octal  |    Binary\n");
	printf("%3s    |    %5s\n","0", "000");
	printf("%3s    |    %5s\n","1", "001");
	printf("%3s    |    %5s\n","2", "010");
	printf("%3s    |    %5s\n","3", "011");
	printf("%3s    |    %5s\n","4", "100");
	printf("%3s    |    %5s\n","5", "101");
	printf("%3s    |    %5s\n","6", "110");
	printf("%3s    |    %5s\n","7", "111");
	return 0;
}
