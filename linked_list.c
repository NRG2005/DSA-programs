#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ListSize (NODE *p_head)
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

void ModifyList (NODE *p_head)
{
	int pos, val;
	NODE *p_temp = p_head, *p_prev;

	printf ("Number of the node you want to modify:");
	scanf ("%d", &pos);
	printf ("The new value:");
	scanf ("%d", &val);

	for (int i = 0; i < (pos - 1); i ++)
		p_temp = p_temp -> next;
	p_temp->data = val;
}


void CreateList (NODE **pp_head)
{
	int num, val;
	NODE *p_node, *p_temp, *p_head;

	p_head = *pp_head;
	printf ("How many nodes do you want to create?:");
	scanf ("%d", &num);

	for (int i = 0; i < num; i ++)
	{
		p_node = CreateNode ();
		
		if (p_head == NULL)
			p_head = p_node;
		else
		{
			for (p_temp = p_head; p_temp -> next != NULL; 
				p_temp = p_temp -> next)
				;
			p_temp -> next = p_node;
		}
	}
	*pp_head = p_head;	
}


void PrintList (NODE *p_head)
{
	NODE *p_node;

	for (p_node = p_head; p_node != NULL; p_node = p_node->next)
		printf ("Val is %d\n", p_node->data);
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

void InsertAtEnd (NODE **pp_head)
{
	NODE *p_head = *pp_head;
	NODE *p_node, *p_temp;

	p_node = CreateNode ();
	
	for (p_temp = p_head; p_temp->next != NULL; p_temp = p_temp->next)
		;
	p_temp->next = p_node;
}

void InsertAnywhere (NODE **pp_head)
{
	int pos;
	int listLen;
	NODE *p_temp = *pp_head, *p_prev, *p_node;

	listLen = ListSize (p_temp);
	printf ("Position at which to insert:");
	scanf ("%d", &pos);

	if (pos == 1)
		InsertAtBeginning (pp_head);
	else if (pos == listLen)
		InsertAtEnd (pp_head);
	else
	{
		for (int i = 0; p_temp != NULL; p_prev = p_temp, p_temp = p_temp->next, i++)
		{
			if (i == (pos - 1))
			{
				p_node = CreateNode ();
				p_prev -> next = p_node;
				p_node -> next = p_temp;
				break;
			}
		}
	}	
}


bool SearchList (NODE *p_head)
{
	NODE *p_temp;
	int value;
	bool found = false;
	NODE *phead = p_head;

	printf ("What are you looking for?:");
	scanf ("%d", &value);
	for (p_temp = phead; p_temp != NULL; p_temp = p_temp->next)
	{
		if (p_temp->data == value)
		{
			found = true;
			break;
		}
	}
	return found; 
}

void DeleteFirstNode (NODE **pp_head)
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

void DeleteLastNode(NODE **pp_head)
{
	NODE *p_head = *pp_head;
	NODE *second_last;
	if (p_head != NULL)
	{
		// If the list has only one node, delete it.
		if (p_head->next == NULL)
		{ 
			free(p_head);
			p_head = NULL;
		}
		else
		{
			// Find the second last node
			second_last = p_head;
    			while (second_last->next->next != NULL)
        			second_last = second_last->next;
    			// Delete the last node
    			free(second_last->next);

    			// Change next of second last
    			second_last->next = NULL;
		}
	}
	else
		printf ("There is nothing to delete\n");
	*pp_head = p_head;
}

void DeleteAnyNode (NODE **pp_head)
{
	int nodeNum, i;
	NODE *p_head = *pp_head;
	int lsize = ListSize (p_head);
	NODE *p_cur, *p_prev;

	printf ("Enter the number of the node you want to delete:");
	scanf ("%d", &nodeNum);

	if (nodeNum < 0 || nodeNum > lsize)
	{
		printf ("Invalid node number\n");
		exit (0);
	}

	if (nodeNum == 1)	// Delete first node
	{
		DeleteFirstNode (pp_head);
		return;
	}

	if (nodeNum == lsize)	// Last node to be deleted
	{
		DeleteLastNode (pp_head);
		return;
	}

	p_cur = p_head;
	for (i = 0; i < (nodeNum - 1); i ++, p_prev = p_cur, p_cur = p_cur -> next)
		;
	p_prev -> next = p_cur -> next;
	free (p_cur);
}



bool IsListEmpty (NODE *p_head)
{
	bool ret_val;

	ret_val = p_head == NULL ? true: false;
	return ret_val;
}


/*
Follow these steps below to solve the problem:

Initialize three pointers prev as NULL, curr as head, and next as NULL.
Iterate through the linked list. In a loop, do the following:
Store the next node, next = curr -> next
Update the next pointer of curr to prev, curr -> next = prev
Update prev as curr and curr as next, prev = curr and curr = next
*/

// Given the head of a list, reverse the list and return the
// head of the reversed list
void ReverseList(NODE **pp_head) 
{
    	// Initialize three pointers: curr, prev and next
    	NODE *curr = *pp_head, *prev = NULL, *next;

    	// Traverse all the nodes of Linked List
    	while (curr != NULL) 
	{
        	// Store next
        	next = curr->next;

        	// Reverse current node's next pointer
        	curr->next = prev;

        	// Move pointers one position ahead
        	prev = curr;
        	curr = next;
    	}

    	// Update the head to point to the reversed list
	*pp_head = prev;
}

// Free the memory taken up by the whole list
void FreeList(NODE **pp_head)
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
