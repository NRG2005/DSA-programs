#include <stdio.h>
#include <limits.h>
#include "DequeFunctions.h"


void addFront(int *arr, int item, int *pfront, int *prear, int maxSize) 
{
  	int i, k, c;

  	if (*pfront == 0 && *prear == maxSize - 1) // one added at the front and 
					// rest of the items added at the back end
	{
    		printf("\nDeque is full.\n");
    		return;
  	}

  	if (*pfront == -1) 	// The first item being added
	{
    		*pfront = *prear = 0;
    		arr[*pfront] = item;
    		return;
  	}

  	if (*prear != maxSize - 1) 	// Pushing out the array elements 
					// to make space for the latest data
	{
    		c = count(arr, maxSize);
    		k = *prear + 1;
    		for (i = 1; i <= c; i++) 
		{
      			arr[k] = arr[k - 1];
      			k--;
    		}
    		arr[k] = item;
    		*pfront = k;
    		(*prear)++;
  	} 
	else 
	{
    		(*pfront)--;
    		arr[*pfront] = item;
  	}
}

void addRear(int *arr, int item, int *pfront, int *prear, int maxSize) 
{
  	int i, k;

  	if (*pfront == 0 && *prear == maxSize - 1) 
	{
    		printf("\nDeque is full.\n");
    		return;
  	}

  	if (*pfront == -1) 
	{
    		*prear = *pfront = 0;
    		arr[*prear] = item;
    		return;
  	}

  	if (*prear == maxSize - 1) 
	{
    		k = *pfront - 1;
    		for (i = *pfront - 1; i < *prear; i++) 
		{
      			k = i;
      			if (k == maxSize - 1)
        			arr[k] = 0;
      			else
        			arr[k] = arr[i + 1];
    		}
    		(*prear)--;
    		(*pfront)--;
  	}
  	(*prear)++;
  	arr[*prear] = item;
}

int delFront (int *arr, int *pfront, int *prear) 
{
  	int item;

  	if (*pfront == -1) 
	{
    		printf("\nDeque is empty.\n");
    		return 0;
  	}

  	item = arr[*pfront];
  	arr[*pfront] = INT_MAX;

  	if (*pfront == *prear)
    		*pfront = *prear = -1;
  	else
    		(*pfront)++;

  	return item;
}

int delRear(int *arr, int *pfront, int *prear) 
{
  	int item;

  	if (*pfront == -1) 
	{
    		printf("\nDeque is empty.\n");
    		return 0;
  	}

  	item = arr[*prear];
  	arr[*prear] = INT_MAX;
  	(*prear)--;
  	if (*prear == -1)
    		*pfront = -1;
  	return item;
}

void display (int *arr, int maxSize) 
{
  	int i;

  	printf("\n front:  ");
  	for (i = 0; i < maxSize; i++)
    		printf("  %d", arr[i]);
  	printf("  :rear");
}

// Returns a count of items filled into the array
int count(int *arr, int maxSize) 
{
  	int c = 0, i;

  	for (i = 0; i < maxSize; i++) 
	{
    		if (arr[i] != INT_MAX)
      			c++;
  	}
  	return c;
}
