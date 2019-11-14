#include <stdio.h>
#include <stdlib.h>

/* data structure */
typedef struct node {
	int key;
	struct node *next;
} Node;

/* external variables */
extern Node *head, *tail;

/*************************************/

/*********************
 *     functions     *
 *********************/

int isEmpty(void)
{
    if(head -> next)
        return 0;
    else
        return 1;
}

int length(void)
{
    int len = 0;
	Node *node = head -> next;
    while(node){
        len++;
        node=node->next;
    }
	return len;
}

void clear(void)
{
	Node *node = head->next;

	while (node) {
		Node *temp = node;
		node = node->next;
		free(temp);
	}

	head->next = NULL;
	tail = head;
}

void insert(int key, int loc)
{
	if (loc > length())
		return;

	Node *node = head;
	for (int i = 0; i < loc; i++)
		node = node->next;

	Node *temp = malloc(sizeof(Node));
	temp->key = key;
	temp->next = node->next;
	node->next = temp;

	if (tail == node)
		tail = temp;
}

void append(int key)
{
    Node *temp = malloc(sizeof(Node));
    temp -> key = key;
    temp -> next = NULL;
    tail -> next = temp;
    tail = temp;
}

void delete(int loc)
{
    if (loc > length()-1)
		return;

	Node *node = head;
    for(int i = 0; i < loc; i++){
        node = node -> next;
    }

    if(node -> next -> next != NULL){
        Node *temp = node -> next;
        node -> next = temp -> next;
        free(temp);
    }
    else{
        free(node -> next);
        node -> next = NULL;
        tail = node;
    }
}
