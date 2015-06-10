#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
	if (argc == 3 ) {
		int changeNum(int num, int mode)
		{
			if (8 == mode){
				puts("Octal.");
				return num + 8;
			}
			if (16 == mode){
				puts("Hex.");
				return num + 16;
			}
			else
				puts("Not this mode.");
			return num;
		}

		printf("%d\n", changeNum(atoi(argv[1]), atoi(argv[2])));
	}

	if (argc == 2) {
		int changeNum(int num) 
		{
			puts("Decimal.");
			return num;
		}

		printf("%d\n",changeNum(atoi(argv[1])));
	}



	return 0;
}
