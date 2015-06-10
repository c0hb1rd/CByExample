#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* statement function */
static void CopyToNode(Item item, Node * pn);
static void CopyToItem(Node * pn, Item * pi);

/* initiadlizetion queue */
void InitializeQueue(Queue * pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

/* check queue whether full */
bool QueueIsFull(const Queue * pq)
{
	return pq->items == MAXQUEUE;
}

/* check queue whether empty */
bool QueueIsEmpty(const Queue * pq)
{
	return pq->items == 0;
}

/* return how many item in this queue */
int QueueItemCount(const Queue * pq)
{
	return pq->items;
}

/* add items to the end of the queue */
bool EnQueue(Item item, Queue * pq)
{
	Node * pnew;

	if (QueueIsFull(pq)) {
		return false;
	}

	pnew = (Node *)malloc(sizeof(Node));
	if (NULL == pnew) {
		fprintf(stderr, "Unable to allocate memory\n");
		exit(1);
	}
	
	CopyToNode(item, pnew);
	pnew->next = NULL;
	
	if (QueueIsEmpty) {
		pq->front = pnew;
	} else {
		pq->rear->next = pnew;    //this pointer(rear->next) belong node
	}

	pq->rear = pnew;    //this pointer(rear) belong queue
	pq->items++;

	return true;
}

/* remove items frome the queue header  */
bool DeQueue(Item * pitem, Queue * pq)
{
	Node * pt;

	if (QueueIsEmpty(pq))
		return false;

	CopyToItem(pq->front, pitem);
	pt = pq->front;
	pq->front = pq->front->next;
	free(pt);
	pq->items--;
	if (0 == pq->items)
		pq->rear = NULL;

	return true;
}

/* free memory */
void EmptyTheQueue(Queue * pq)
{
	Item dummy;
	while (!QueueIsEmpty(pq))
		DeQueue(&dummy, pq);
}

static void CopyToNode(Item item, Node * pn)
{
	pn->item = item;
}

static void CopyToItem(Node * pn, Item * pi)
{
	*pi = pn->item;
}
