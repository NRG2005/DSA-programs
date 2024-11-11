#include<stdio.h>
#define stacksize 50
static int stack1[stacksize];
static int top = -1;

/*void CreateStack()
{
	int stack1[stacksize];
	int element;
	printf("Enter the number of elements in the stack : ");
	scanf("%d",&stacksize);
	for(int i=0;i<n;i++)
	{
		printf("Enter the element : ");
		scanf("%d",&element);
		stack1[n-i] = element;
	}
	for(int i=0;i<=stacksize;i++)
	{
		printf("%d",stack1[i]);
	}
}
*/

int push (int stack1, int value, int maxSize)// Pass the array, top (index) of stack and the maximum // size of the stack 
{
	printf("Enter the value of the element you want to enter : ");
	scanf("%d",&value);
	if(top<maxSize)
	{
		stack1[top] = value;
		stack1[i] = stack1[i+1];
	}
	else
	{
		printf("Stack Overflow\n");
	}
	return top;
} 

int pop (int top) 		// Pass top (index) of stack
{
	top--;
	printf("%d",stack1);
	return 0;
}

void peek (int stack1[stacksize], int top)
{
	int index;
	printf("Enter the index you want to search in : ");
	scanf("%d",&index);
	printf("Element in index %d is %d\n",index,stack1[index]);
}	

bool isEmpty (int top)
{
	if(top == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}		

void printStack (int stack1[], int top)
{
	for(int i=0;i<=stacksize;i++)
	{
		printf("%d",stack1[i]);
	}
}	
