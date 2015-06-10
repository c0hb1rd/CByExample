#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
	if (argc != 3) {
		puts("Error.");
		exit(1);
	}

	char str[100];

	sprintf(str, "python page.py > %s\.html 0<%s\.txt", argv[1], argv[2]);
	system(str);

	return 0;
}
