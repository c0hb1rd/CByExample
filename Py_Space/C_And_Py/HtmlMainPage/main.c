#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
	if (2 != argc) {
		puts("Error.");
		return 1;
	}

	char cmd[100];

	sprintf(cmd, "python /bin/htmlMainPage.py > %s\.html", argv[1]);

	system(cmd);

	return 0;
}
