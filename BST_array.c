#include<stdio.h>
#include<stdlib.h>

int child(int tree[])
{
	int n;
	int root;
	char value;
	char right_child;
	char left_child;
	printf("Enter the number of nodes in the tree : ");
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		printf("Enter the value in the node : ");
		scanf("%c",&value);
		value = tree[i];
	}
	printf("Enter the index of the root node (0 or 1) : ");
	scanf("%d",&root);
	if(root<0 || root>1)
	{
		printf("The root is invalid\n");
	}
	else if(root == 0 || root == 1)
	{
		for(int i=0;i<=n;i++)
		{
			if(tree[i] != '\0' && ((2*i)+1) <= n)
			{
				right_child = tree[2*i];
				left_child = tree[2*i]+1;
			} 
		}
	}
	printf("left child = %c\n",left_child);
	printf("right child = %c\n",right_child);
	return 0;
}