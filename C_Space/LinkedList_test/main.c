#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* macro */
#define TSIZE 45

struct film {
	char title[TSIZE];
	int rating;

	struct film * next;
};

int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];

	puts("Enter first movie title: ");
	while(gets(input) != NULL && input[0] != '\0') {
		/*          point step
		** if (head == NULL) head = current
		** else prev->next = current
		** current->next = NULL
		** prev = current
		*/
		current = (struct film *)malloc(sizeof(struct film));

		if (head == NULL) 
			head = current;
		else
			prev->next = current;

		current->next = NULL;

		/* get information */
		strcpy(current->title, input);
		puts("Enter your rating <0-10>: ");
		scanf("%d", &current->rating);
		while(getchar() != '\n')
			continue;

		/*  */
		puts("Enter next movie title(empty line to quit): ");
		prev = current;
	}

	/* show information */
	if (head == NULL)
		puts("No data entered.");
	else
		puts("Here is the movie list: ");

	/* point */
	current = head;
	while(current != NULL) {
		printf("Moive: %s\n\tRating: %d\n", current->title, current->rating);
		current = current->next;
	}

	puts("Bye!");

	return 0;
}
