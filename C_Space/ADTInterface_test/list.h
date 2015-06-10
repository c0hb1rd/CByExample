/* judgement */
#ifndef LISH_H
#define LISH_H 

#include <stdbool.h>

/* macro */
#define TSIZE 45
#define DEBUG 0
#if DEBUG
	#define CK(X) puts(X)
#else
	#define CK(X) ;
#endif

/* ADT */
typedef struct contact {
	char name[TSIZE];
	char number[TSIZE]; 
} Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef Node * List;

/*      ANOTHER WAY
**  typedef struct list {
**  	Node * head;
**  	Node * end;
**  } List;
*/

/* intializetion a list */
void InitializeList(List * plist);

/* judgement a list whether empty*/
bool ListIsEmpty(const List * plist);

/* judgement a list whether full */
bool ListIsFull(const List * plist);

/* return how many item in this list */
unsigned int ListItemCount(const List * plist);

/* add a new item at the last */
bool AddItem(Item item, List * plist);

/* each item using function */
void Traverse(const List * plist, void (* pfun)(Item item));

/* free memory */
void EmptyTheList(List * plist);
 
#endif
