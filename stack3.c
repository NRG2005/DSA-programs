#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack1.c"

int StackSize (NODE *p_head)
{
	int count = 0;
	NODE *p_node = p_head;

	for (count = 0; p_node != NULL; p_node = p_node->next)
		count ++;
	return count;
}

// Creates a node; allocates memory, gets the data value, etc
NODE *CreateNode ()
{
 	NODE *p_node;
	if ((p_node = (NODE *) malloc (sizeof (NODE))) == NULL)
	{
		printf ("Unable to create node: memory not available\n");
		exit (0);		
	}
	p_node -> next = NULL;
	printf ("Key in the value:");
	scanf ("%d", &p_node->data);
	return p_node;
}

void CreateStack (NODE **pp_head)
{
	int num, val;
	NODE *p_node, *p_temp, *p_head;

	p_head = *pp_head;
	printf ("How many items do you want to push?:");
	scanf ("%d", &num);

	for (int i = 0; i < num; i ++)
	{
		p_node = CreateNode ();
		if (p_head != NULL)
			p_node -> next = p_head;
		p_head = p_node;
	}
	*pp_head = p_head;
}


void PrintStack (NODE *p_head)
{
	NODE *p_node;

	for (p_node = p_head; p_node != NULL; p_node = p_node->next)
		printf ("Val is %d\n", p_node->data);
}

void push (NODE **pp_head)
{
	InsertAtBeginning (pp_head);
}


void pop (NODE **pp_head)
{
	DeleteLatestEntry (pp_head);
}

void peek (NODE **pp_head)
{
	NODE *p_head = *pp_head;

	if (p_head != NULL)
		printf ("Entry at the top is %d\n", p_head->data);
}


void InsertAtBeginning (NODE **pp_head)
{
	NODE *p_node;
	NODE *p_head = *pp_head;

	p_node = CreateNode ();
	p_node -> next = p_head;
	p_head = p_node;
	*pp_head = p_head;
}


void DeleteLatestEntry (NODE **pp_head)
{
	NODE *p_temp;
	NODE *p_head = *pp_head;

	if (p_head != NULL)
	{
		p_temp = p_head;
		p_head = p_head -> next;
		free (p_temp);
	}
	else
		printf ("There is nothing to delete\n");
	*pp_head = p_head;
}


bool IsStackEmpty (NODE *p_head)
{
	bool ret_val;

	ret_val = p_head == NULL ? true: false;
	return ret_val;
}


// Free the memory taken up by the whole list
void FreeStack(NODE **pp_head)
{
    	NODE *current = *pp_head;
    	NODE *nextNode;
    	while (current != NULL)
    	{
		nextNode = current->next;
        	free(current);
        	current = nextNode;
    	}
    	*pp_head=NULL;
}