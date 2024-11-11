//		QueueArray.h

static int element;
static int queue1[queuesize];
static int first = queue1[0];
static int last = queue1[queuesize]

void Enqueue (int element, int n, int queuesize, int queue1)
{
	printf("Enter the size of the queue : ");
	scanf("%d",&queuesize);
	for(int i=0;i<=queuesize;i++)
	{
		int element;
		printf("Enter the element you want to enter : ");
		scanf("%d",&element);
		queue1[queuesize-i] = element;
	}
}

int Dequeue (int x, int queue1)	// Return the first value and remove it
{
	if(last == NULL)
	{
		printf("Queue is empty");
	}
	x = first--;
	printf("Removed element is : %d\n",x);
}

int Peek (int first)	// Return the first value, keep it in the q
{
	printf("%d",first);
}

bool isFull (int, int)		// Check whether queue is full
{
	if(last != NULL)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool isEmpty (int first)	// Check whether queue is empty
{
	if(first == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}