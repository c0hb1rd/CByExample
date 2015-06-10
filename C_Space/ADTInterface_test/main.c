#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/* statement function */
void showcontacts(Item item);

int main(void)
{
	List contacts;
	Item temp;

	/* initializetion */
	InitializeList(&contacts);
	if (ListIsFull(&contacts)) {
		fprintf(stderr, "No memory available! Bye.\n");
		exit(1);
	}

	puts("Enter frist contact name: ");
	while(gets(temp.name) != NULL && temp.name[0] != '\0') {
		printf("Enter %s number: ", temp.name);
		
		gets(temp.number);
		
		CK("26");
		if(AddItem(temp, &contacts) == false) {
				puts("28");
				fprintf(stderr,"Problem allocating memory.\n");
			break;
		}
		CK("31");
		if(ListIsFull(&contacts)) {
			puts("The list is now full.");
			break;
		}
		CK("37");
		puts("Enter next contact name(empty line to quit): ");
	}
	
	if (ListIsEmpty(&contacts))
			puts("No data entered.");
	else {
		puts("Here is the contacts list: ");
		Traverse(&contacts, showcontacts);
	}

	printf("You entered %u contacts.\n", ListItemCount(&contacts));

	EmptyTheList(&contacts);
	puts("Bye!");

	return 0;
}

void showcontacts(Item item)
{
	printf("Contact name: %s\n\tNumber: %s\n", item.name, item.number);
}
