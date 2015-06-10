#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct test{
	char * title;
	char * author;
};

void getinfo(struct test *);

int main(int argc, char * argv[])
{
	if(2 != argc)
		return 1;	

	FILE * fp;
	struct test book;

	fp = fopen(argv[1], "a+");

	getinfo(&book);

	fprintf(fp,"The book of title: %s\nThe book of author: %s\n", book.title, book.author);

	fclose(fp);

	return 0;
}

void getinfo(struct test * pst)
{
	char * str, * str2;
	str = (char *)malloc(100 * sizeof(char));
	str2 = (char *)malloc(100 * sizeof(char));

	gets(str);	
	gets(str2);

	pst->title = (char *)malloc(100 * sizeof(char));
	strcpy(pst->title, str);

	pst->author = (char *)malloc(100 * sizeof(char));
	strcpy(pst->author, str2);
}
