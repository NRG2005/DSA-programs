typedef struct node
{
	int data;
	struct node *next;
	//struct node *prev;
} NODE;


struct node* CreateNode(int element) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->element = element; 
    new_node->next = NULL; 
    new_node->prev = NULL; 
    return new_node; 
} 

void CreateList (NODE **, NODE **)
{
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
}

void InsertAtBeginning (NODE **, NODE **);
void InsertAtEnd (NODE **, NODE **);
void InsertAnywhere (NODE **, NODE **);
void DeleteFirstNode (NODE **, NODE **);
void DeleteLastNode (NODE **, NODE **);
void DeleteAnyNode (NODE **, NODE **);
void ModifyList (NODE *);
bool SearchList (NODE *);
void PrintList (NODE **);
bool IsListEmpty (NODE *);
void FreeList (NODE **);