#include <stdio.h>
#include <stdlib.h>

typedef struct tNode 
{
	int data;
	struct tNode* left;
	struct tNode* right;
}tNode;

/* Function to traverse the binary tree without recursion
and without stack */
void TreeTraversal(tNode* root)
{
	tNode *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL) 
	{

		if (current->left == NULL) 
		{
			printf("%d ", current->data);
			current = current->right;
		}
		else 
		{

			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Make current as the right child of its
			inorder predecessor */
			if (pre->right == NULL) 
			{
				pre->right = current;
				current = current->left;
			}

			/* Revert the changes made in the 'if' part to
			restore the original tree i.e., fix the right
			child of predecessor */
			else 
			{
				pre->right = NULL;
				printf("%d ", current->data);
				current = current->right;
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */
}

tNode* newtNode(int data)
{
	tNode* node = (tNode *)malloc(sizeof(tNode));
	if (node == NULL)
	{
		printf ("Could not allocate memory\n");
		exit (0);
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
