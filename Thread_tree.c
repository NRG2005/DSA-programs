#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//#include"main"

struct Node
{
	int data_value;
	struct Node* left_node;
	struct Node* right_node;
	bool left_thread;
	bool right_thread;
}

struct NODE* createNode(int data_value) 
{
    if (data_value == -1) {
        return NULL;  
    }
    struct NODE* p_node = (struct NODE*)malloc(sizeof(struct NODE));
    if (p_node == NULL) {
        printf("Memory allocation failed\n");
    }
    p_node->data = data;
    p_node->left = p_node->right = NULL;
    return p_node;
}


