//		QueueList.h

typedef struct node
{
	int data;
	struct node *next;
} NODE;

typedef struct queue
{
	NODE *front;
	NODE *rear;
} QUEUE;

struct node* CreateNode(int element) 
{ 
    node* p = (node*)malloc(sizeof(struct node)); 
    p->element = element; 
    p->next = NULL; 
    return new_node; 
} 

void InitData ()
{
	int element;
	mq.front = NULL;
	mq.rear = NULL;
	printf("Enter the element : ");
	scanf("%c",&element);
	atoi(element);
}


struct node* CreateList(int element)
{
	int num, val;
	NODE *p_node, *p_temp;
	p_front = *pp_front;
	printf ("How many items do you want to add?:");
	scanf ("%d", &num);

	for (int i = 0; i < num; i ++)
	{
		p_node = CreateNode(element);
		if (p_front != NULL)
			p_node -> next = p_front;
		p_front = p_node;
	}
	*pp_front = p_front;
}

void Enqueue (int x)
{
	NODE *p_node;
	NODE *p_first = *pp_first;

	p_node = CreateNode();
	p_node -> next = p_first;
	p_first = p_node;
	*pp_first = p_first;
}

int Dequeue ()	// Return the first value and remove it
{
	NODE *p_temp;
	NODE *p_front = *pp_front;

	if (p_front != NULL)
	{
		p_temp = p_front;
		p_ = p_head -> next;
		free (p_temp);
	}
	else
		printf ("There is nothing to delete\n");
	*pp_head = p_head;
}
int Peek ();		// Return the first value, keep it in the q
bool isEmpty ();	// Check whether queue is empty
void DisplayQ ();
void freeList ();