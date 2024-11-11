#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char data;
	struct node* left;
	struct node* right;
}NODE;

NODE *CreateLeftNode(char[])
{
	NODE *p_node;
	p_node = (NODE *) malloc (sizeof (NODE));
	if(p_node == NULL)
	{
		printf("Data could not be allocated");
		exit();
	}
	NODE->data = data;
	NODE->left = NULL;
	return NODE;
}

NODE *CreateRightNode(char [])
{
	NODE *p_node;
	p_node = (NODE *) malloc (sizeof (NODE));
	if(p_node == NULL)
	{
		printf("Data could not be allocated");
		exit();
	}
	NODE->data = data;
	NODE->right = NULL;
	return NODE;
}

void push(NODE *char[])
{
	if(NODE *char[] == NULL)
	{
		printf("The node is empty\n");
		exit();
	}
	if(NODE *char[].isalpha() == 1)
	{
		
	}

}