#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyToNode(Item item, Node * pnode);

/* initializetion list */
void InitializeList(List * plist)
{
	*plist = NULL;
}

/* judgement a list whether empty*/
bool ListIsEmpty(const List * plist)
{
	if (*plist == NULL)
		return true;
	else
		return false;
}

/* judgement a list whether full */
bool ListIsFull(const List * plist)
{
	Node * prev;
	bool full;
	prev = (Node *)malloc(sizeof(Node));

	if (prev == NULL)
		full = true;
	else
		full = false;
	
	free(prev);
	
	return full;
}

/* return how many item in this list */
unsigned int ListItemCount(const List * plist)
{
	unsigned int count = 0;
	Node * prev = * plist;

	while(prev != NULL) {
		count ++;
		prev = prev->next;
	}

	return count;
}

/* add a new item at the last */
bool AddItem(Item item, List * plist)
{
	Node * pnew;
	Node * scan = * plist;    //Node * scan; scan = &(*plist);
	CK("l 58");
	pnew = (Node *)malloc(sizeof(Node));
	CK("l 60");
	if (pnew == NULL)
		return false;
	CK("l 63");
	CopyToNode(item, pnew);
	pnew->next = NULL;
	CK("l 69");
	if (scan == NULL){
		CK("l 71");
		*plist = pnew;
		CK("l 73");
	}
	else {
		while(scan->next != NULL) {
			CK("l 77");
			scan = scan->next;
		}
		CK("l 80");
		scan->next = pnew;
	}
	
	return true;
}

/* each item using function */
void Traverse(const List * plist, void (* pfun)(Item item))
{
	Node * prev = * plist;
	while(prev != NULL) {
		(* pfun)(prev->item);
		prev = prev->next;
	}
}	

/* free memory */
void EmptyTheList(List * plist)
{
	Node * prev;
	while(*plist != NULL) {
		prev = (*plist)->next;
		free(*plist);
		*plist = prev;
	}
}

/* copy item data in node */
static void CopyToNode(Item item, Node * pnode)
{
	pnode->item = item;
}
