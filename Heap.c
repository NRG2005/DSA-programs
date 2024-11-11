#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct Heap
{
	int* arr;
	int size;
	int capacity;
}Heap;

Heap* root = NULL;

heap* createHeap(int capacity, int* nums)
{
    Heap* node = (Heap*)malloc(sizeof(Heap));
    if (h == NULL) {
        printf("Memory could not be allocated");
        return NULL;
    }
    node->size = 0;
    node->capacity = capacity;
    node->arr = (int*)malloc(capacity * sizeof(int));
    if (node->arr == NULL) 
    {
        printf("Memory was not allocated");
        return NULL;
    }
    for (int i = 0; i < capacity; i++) 
    {
        node->arr[i] = nums[i];
    }
    
}

void Maxheapify(Heap* node, int size, int s)
{
	int largest = 0;
	int left = 2*s;
	int right = (2*s)+1;
	int max = s;

	if (node->s <= left || left < 0)
	{
        left = -1;
	}
    if (node->s <= right || right < 0)
    {
        right = -1;
    }

    if (node->arr[left] > node->arr[max])
    {
        max = left;
    }
    if (node->arr[right] > node->arr[max])
    {
        max = right;
    }

    int temp = node->arr[max];
    node->arr[max] = node->arr[s];
    node->arr[s] = temp;
    maxHeapify(node, max);
}

struct Heap* Insert(Heap* node, int size, int s)
{
	int value;
	int swapvalue;
	printf("Enter the value you want to insert into the heap : ");
	scanf("%d",&value);
	arr[size+1] = value;

	//change in array
	for(int i=size;i>=0;i--)
	{
		if(arr[size]>arr[size-1])
		{
			arr[size-1] = swapvalue;
			arr[size] = arr[size-1];
			arr[size] = swapvalue;
		}
	}
	printf("Array after inserting new value is : %d\n",&arr[]);

	//change in the heap
	if (node->size < node->capacity) 
	{
		node->arr[node->size] = data;
		if(node->size < node->capacity)
		{
			int parent = s / 2;
    		if (node->arr[parent] < node->arr[s]) 
    		{
        		int temp = node->arr[parent];
        		node->arr[parent] = node->arr[s];
        		node->arr[index] = temp;
       		}
        
		}
		node->size++;
	}

}

struct Heap* Delete(Heap* node, int size, int s)
{
	int value;
	printf("Enter the value you want to delete : ");
	scanf("%d",&value);
    if (s == -1) 
    {
        printf("Value not found in the heap\n");
        return;
    }
    node->arr[s] = node->arr[node->size - 1];
    heap->size--;
    Maxheapify(Heap* node, int size, int s);
}


int main()
{
	struct Heap* arr = (struct Heap*)malloc(sizeof(struct Heap));
	int value;
	printf("Enter the array size : ");
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<=size;i++)
	{
		scanf("%d",&value);
		arr[i]=(struct Heap*)malloc(sizeof(struct Heap));
	}
	for(int i=0;i<=size;i++)
	{
		if(arr[i]<arr[i+1])
		{
			arr[i] = arr[i+1];
		}
	}
}