#pragma c9x on
#ifndef QUEUE_H
#define QUEUE_H


#include <stdbool.h>

/* macro */
#define NAME    //define name of item 
#define MAXQUEUE 10
#define DEBUG 0
#if DEBUG
	#define CK(X) puts(X)
#else
	#define CK(X) ;
#endif

typedef struct NAME {
	
	//method

} Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef struct queue {
	Node * front;
	Node * rear;
	int items;
} Queue;

/* initiadlizetion queue */
void InitializeQueue(Queue * pq);

/* check queue whether full */
bool QueueIsFull(const Queue * pq);

/* check queue whether empty */
bool QueueIsEmpty(const Queue * pq);

/* return how many item in this queue */
int QueueItemCount(const Queue * pq);

/* add items to the end of the queue */
bool EnQueue(Item item, Queue * pq);

/* remove items frome the queue header  */
bool DeQueue(Item * pitem, Queue * pq);

/* free memory */
void EmptyTheQueue(Queue * pq);

#endif

