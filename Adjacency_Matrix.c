#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Adj_Matrix_Utils.h"

static int adj [MAX][MAX];

bool create_edge (int num_nodes)
{
    int origin, destin;
    bool retVal = false;

    printf ("Entering (0 0) or row col > num of nodes will not create a node\n");
    printf("Enter edge (row col) : ");
    scanf("%d %d", &origin, &destin);
    if ((origin != 0) && (destin != 0))
    {
        if (origin > num_nodes || destin > num_nodes 
		    || origin <= 0 || destin <= 0) 
            printf("Invalid edge!\n");
        else
        {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;
            retVal = true;
        }
    }
    return retVal;
}


void create_graph(int num_nodes) 
{
    int i, max_edges, origin, destin;

    max_edges = num_nodes * (num_nodes - 1);
 
    for (i = 1; i <= max_edges; i++) 
    {
        if (!create_edge (num_nodes))
            break;
    }
}
 
void display(int num_nodes) 
{
    int i, j;
    int n = num_nodes;
    for (i = 1; i <= n; i++) 
    {
        for (j = 1; j <= n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}
 
void insert_node(int *num_node) 
{
    int i;
    int n = *num_node;  
    n++;
    printf("The inserted node is %d \n", n);
    for (i = 1; i <= n; i++) 
    {
        adj[i][n] = 0;
        adj[n][i] = 0;
    }
    *num_node = n;
}
 
void delete_node(char u, int *num_nodes) 
{
    int i, j;
    int n = *num_nodes;
    if (n == 0) 
    {
        printf("Graph is empty\n");
        return;
    }
    if (u > n) 
    {
        printf("This node is not present in the graph\n");
        return;
    }
    for (i = u; i <= n - 1; i++)
        for (j = 1; j <= n; j++) 
        {
            adj[j][i] = adj[j][i + 1];
            adj[i][j] = adj[i + 1][j];
        }
    n--;
    *num_nodes = n;
}
