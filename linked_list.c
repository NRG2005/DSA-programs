typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
} NODE;

static struct node* head = NULL; 
static struct node* tail = NULL; 

static int element;


struct node* CreateNode(int element) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->element = element; 
    new_node->next = NULL; 
    new_node->prev = NULL; 
    return new_node; 
} 


void DisplayNode (NODE *)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
	int index;
	printf("Enter the index of the element you want to view : ");
	scanf("%d",&index);
	if(head == NULL)
	{
		printf("The list is empty");
	}
	else
	{
		for(int i=0;i<=index;i++)
		{
			new_node = new_node->next;
			if(i == index)
			{
				printf("%d",new_node->element);
			}
		}
	}
}


void CreateList ()
{
	int n;
	int element;
	printf("Enter the number of elements in the list : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("Enter the element : ");
		scanf("%d",&element);
		struct node *p = CreateNode(element);
		if(head==NULL)
		{
			head=p;
			tail=p;	
		}

	}
}

void InsertAtBeginning ()
{
    struct node* new_node = CreateNode(element); 
    if (head == NULL) { 
        head = new_node; 
        tail = new_node; 
    } 
    else { 
        new_node->next = head; 
        head->prev = new_node; 
        head = new_node; 
    } 
}

void InsertAtEnd ()
{
	struct node* new_node = CreateNode(element);
	if(tail == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else{
		new_node->next = tail;
		tail->prev = new_node;
		tail = new_node;
	}
}

void InsertAnywhere ()
{
	int n;
	int element;
	printf()

}

void DeleteFirstNode ()
{
	struct node* new_node = CreateNode(element);	
	if(head == NULL)
	{
		printf("The list is empty");
	}
	else
	{
		new_node = head;
		head = head->next;
		head->prev = NULL;
		free(new_node);
	}
}

void DeleteLastNode ()
{
	struct node* new_node = CreateNode(element);
	if(head == NULL)
	{
		printf("The list is empty");
	}
	else
	{
		new_node = tail;
		tail = tail->next;
		tail->prev = new_node;
		free(new_node);
	}
}

void DeleteAnyNode ()
{
	struct node* new_node = CreateNode(element);
	Node *new_node_temp;
	int index;
	printf("Enter the index of the node you want to delete : ");
	scanf("%d",&index);
	if(head == NULL)
	{
		printf("The list is empty");
	}
	else
	{
		for(int i=0;i<index;i++)
		{
			new_node_temp = new_node;
			new_node->next = new_node;
		}
		new_node_temp->next = new_node;
		new_node->prev = new_node_temp;
		free(new_node_temp);
	}
}

void NavigateList ()
{
	 struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
	 char choice;
	 printf("Enter the position to navigate to : N(Next Node),P(Previous Node),F(First Node),L(Last Node\n");
	 scanf("%c",&choice);


}

void ModifyList ()
{
	 struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
	 int index;
	 printf("Enter the index where you want to replace the character : ");
	 scanf("%d",&index);
	 

}
bool SearchList ();
void PrintList ();
void ReversePrint ();
bool IsListEmpty ();
void FreeList ();