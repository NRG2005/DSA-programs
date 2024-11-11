//			DequeFunctions.h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "QueueArray.h"

void addFront(int *p_rear, int max_size, int *p_front, int *, int myQueue[])
{
	int front = *p_front;

	if (rear <= (max_size - 1))
	{
		myQueue [front] = data;
		front->next = NULL;
	}
	else
		printf ("Queue is full\n");
}

void addRear(int *, int, int *, int *, int);
int delFront(int *, int *, int *);
int delRear(int *, int *, int *);
void display(int *, int);
int count(int *, int);