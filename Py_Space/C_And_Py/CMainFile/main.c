#include <stdio.h>
#include <stdlib.h>

/* macro */
#define SIZE 100

/* function statement */


int main(int argc, const char * argv[])
{
	if (2 != argc) {
		puts("Error");
		return 1;
	}

	char cmd[SIZE];
	
	sprintf(cmd, "python /bin/cMainFile.py > %s", argv[1]);

	system(cmd);

	return 0;
}
