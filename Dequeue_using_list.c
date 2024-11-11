#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "DequeList.h"

NODE* NewNode()
{
	NODE* node;
	node=(NODE *)malloc(sizeof(NODE));
    	
	if(node!=NULL)
	{
		node->info=0;
		node->next=NULL;
		return node;
	}
	else
	{
		printf("\nmemory not available\n");
		exit(1);
	}
}

int Dequeue (NODE **p_front, NODE **p_rear)   //delete at the beginning
{
	NODE *front = *p_front;
	NODE *rear = *p_rear;
	int item = INT_MAX;
	NODE *temp;

	if(front != NULL)
	{
		temp=front;
		item=temp->info;
		front=front->next;
		*p_front = front;
		if (front == NULL)
			*p_rear = NULL;
		free(temp);
	}
	else
		printf("\nQueue Underflow");
	return item;
}

void Enqueue(int item, NODE **p_front, NODE **p_rear)  //insertion at the end
{
	NODE *front = *p_front;
	NODE *rear = *p_rear;
	NODE* node = NewNode();
	node->info=item;
	if(front==NULL)
	{
		front=node;
		rear=node;
	}
	else
	{
		rear->next=node;
		rear=node;
	}
	*p_front = front;
	*p_rear = rear;
}

int DeleteLast (NODE **p_front, NODE **p_rear)        
{
	NODE *temp, *ptr;
	NODE *front = *p_front;
	NODE *rear = *p_rear;
	int ret_val = INT_MAX;

	
	if (front != NULL)
	{
	    	if(front==rear)
    		{
			ret_val = front-> info;
        		free(front);
        		*p_front=NULL;
        		*p_rear=NULL;
        		return ret_val;
		}
    	
		else
			ptr = front;
    		while(ptr->next!=rear)
    		{
        		ptr=ptr->next;
  		}
		if (rear != NULL)
			ret_val = rear -> info;
    		temp=rear;
    		rear=ptr;
  		ptr->next=NULL;
		*p_front = front;
		*p_rear = rear;
    		free(temp);
	}
	return ret_val;
}

void InsertFirst(int item, NODE **p_front, NODE **p_rear)
{
	NODE *front = *p_front;
	NODE *rear = *p_rear;
    	NODE *node=NewNode();
    	node->info=item;
    	if(front==NULL)
    	{
		printf ("front is NULL\n");
		*p_front=node;
		*p_rear=node;
		return;
	}
    	node->next=front;
    	front=node;
	*p_front = front;
	*p_rear = rear;
}

void PrintList (NODE **p_front)
{
	NODE *front = *p_front;
	NODE *ptr;
	if(front==NULL)
	{
		printf("\nQueue is empty\n");
		return;
	}
	ptr=front;
	printf("\n\nThe linked list implementation of dequeue :\n\n");
	while(ptr != NULL)
	{
		printf("%d->",ptr->info);
		ptr=ptr->next;
	}
	printf("NULL\n");
	return;
}
