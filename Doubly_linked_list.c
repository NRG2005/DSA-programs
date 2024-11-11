
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "DLList.h"

static NODE *head = NULL;
static NODE *tail = NULL;

int ListSize ()
{
	int count = 0;
	NODE *p_node = head;

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
	p_node -> prev = NULL;
	printf ("Key in the value:");
	scanf ("%d", &p_node->data);
	return p_node;
}

void ModifyList ()
{
	int pos, val;
	NODE *p_temp = head, *p_prev;

	printf ("Number of the node you want to modify:");
	scanf ("%d", &pos);
	printf ("The new value:");
	scanf ("%d", &val);

	for (int i = 0; i < (pos - 1); i ++)
		p_temp = p_temp -> next;
	p_temp->data = val;
}


void CreateList ()
{
	int num, val;
	NODE *p_node, *p_temp;

	printf ("How many nodes do you want to create?:");
	scanf ("%d", &num);

	for (int i = 0; i < num; i ++)
	{
		p_node = CreateNode ();
		
		if (head == NULL)
			head = tail = p_node;
		else
		{
			for (p_temp = head; p_temp -> next != NULL; 
				p_temp = p_temp -> next)
				;
			p_temp -> next = p_node;
			p_node -> prev = p_temp;
			tail = p_node;
		}
	}	
}


void PrintList ()
{
	NODE *p_node;

	for (p_node = head; p_node != NULL; p_node = p_node->next)
		printf ("Val is %d\n", p_node->data);
}

void ReversePrint ()
{
	NODE *p_node;

	for (p_node = tail; p_node != NULL; p_node = p_node->prev)
		printf ("Val is %d\n", p_node->data);
}


void InsertAtBeginning ()
{
	NODE *p_node;

	p_node = CreateNode ();
	p_node -> next = head;
	head -> prev = p_node;
	head = p_node;
}

void InsertAtEnd ()
{
	NODE *p_node, *p_temp;

	p_node = CreateNode ();
	
	for (p_temp = head; p_temp->next != NULL; p_temp = p_temp->next)
		;
	p_temp->next = p_node;
	p_node -> prev = p_temp;
	tail = p_node;
}

void InsertAnywhere ()
{
	int pos;
	int listLen;
	NODE *p_temp = head, *p_prev, *p_node;

	listLen = ListSize ();
	printf ("Position at which to insert:");
	scanf ("%d", &pos);

	if (pos == 1)
		InsertAtBeginning ();
	else if (pos == listLen)
		InsertAtEnd ();
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


bool SearchList ()
{
	NODE *p_temp;
	int value;
	bool found = false;

	printf ("What are you looking for?:");
	scanf ("%d", &value);
	for (p_temp = head; p_temp != NULL; p_temp = p_temp->next)
	{
		if (p_temp->data == value)
		{
			found = true;
			break;
		}
	}
	return found; 
}

void DeleteFirstNode ()
{
	NODE *p_temp;

	if (head != NULL)
	{
		p_temp = head;
		head = head -> next;
		head -> prev = NULL;
		if (head -> next == NULL)	// If only one node is left
			tail = head;
		free (p_temp);
	}
	else
		printf ("There is nothing to delete\n");
}

void DeleteLastNode()
{
	NODE *second_last;
	if (head != NULL)
	{
		// If the list has only one node, delete it.
		if (head->next == NULL)
		{ 
			free(head);
			head = NULL;
		}
		else
		{
			// Find the second last node
			second_last = head;
    			while (second_last->next->next != NULL)
        			second_last = second_last->next;
    			// Delete the last node
			tail = second_last;
    			free(second_last->next);

    			second_last->next = NULL;
		}
	}
	else
		printf ("There is nothing to delete\n");
}

void DeleteAnyNode ()
{
	int nodeNum, i;
	int lsize = ListSize ();
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
		DeleteFirstNode ();
		return;
	}

	if (nodeNum == lsize)	// Last node to be deleted
	{
		DeleteLastNode ();
		return;
	}

	p_cur = head;
	for (i = 0; i < (nodeNum - 1); i ++, p_prev = p_cur, p_cur = p_cur -> next)
		;
	p_prev -> next = p_cur -> next;
	free (p_cur);
}

bool IsListEmpty ()
{
	bool ret_val = false;
	if (head == NULL)
		ret_val = true;
	return ret_val;
}

void NavigateList ()
{
	char sub_opt;
	NODE *p_node = head;
	bool go_on = true;

	while (1)
	{
		printf ("Select: P - Previous N - Next F - First L - Last: R - Return:");
		scanf (" %c", &sub_opt);
		sub_opt = toupper (sub_opt);
		switch (sub_opt)
		{
			case 'F':
				p_node = head;
			break;

			case 'L':
				p_node = tail;
			break;

			case 'P':
				p_node = p_node -> prev;
				if (p_node == NULL)
					p_node = head;
			break;

			case 'N':
				p_node = p_node -> next;
				if (p_node == NULL)
					p_node = tail;
			break;

			case 'R':
				go_on = false;
			break;

			default:
				printf ("Invalid option\n");
		}
		if (go_on == false)
			break;
		DisplayNode (p_node);
	}
} 

void DisplayNode (NODE *p_node)
{
	if (p_node != NULL)
		printf ("Data is %d\n", p_node->data);
}

// Free memory alloted to all the nodes in the list
void FreeList()
{
    	NODE *current = head;
    	NODE *nextNode;
    	while (current != NULL)
    	{
		nextNode = current->next;
        	free(current);
        	current = nextNode;
    	}
    	head=NULL;
}
