#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* data structure */
typedef struct node {
	int key;
	struct node *next;
} Node;

/* linked lists functions */
int isEmpty(void);
int length(void);
void clear(void);
void insert(int key, int loc);
void append(int key);
void delete(int loc);

/* global variables */
Node *head, *tail;

/* stack functions */
void ISEMPTY();
void PEEK();
void PUSH(int n);
void POP();
void SEARCH(int n);

int main(){

    char input[10];

    char command[5][10] = {
        "ISEMPTY",
        "PEEK",
        "PUSH",
        "POP",
        "SEARCH"
    };

    head = tail = calloc(1, sizeof(Node));

    while(scanf("%s", input) == 1){
        if(strcmp(command[0], input) == 0){         //ISEMPTY
            ISEMPTY();
        }
        else if(strcmp(command[1], input) == 0){     //PEEK
            PEEK();
        }
        else if(strcmp(command[2], input) == 0){     //PUSH
            int a;
            scanf(" %d", &a);
            PUSH(a);
        }
        else if(strcmp(command[3], input) == 0){     //POP
            POP();
        }
        else if(strcmp(command[4], input) == 0){     //SEARCH
            int a;
            scanf(" %d", &a);
            SEARCH(a);
        }
    }

    clear();
	free(head);

    return 0;
}

/* stack functions */

void ISEMPTY(){
    if(isEmpty()) printf("Y\n");
    else printf("N\n");
}

void PEEK(){
    if(isEmpty()){
        printf("-1\n");
        return;
    }
    else{
        printf("%d\n", tail -> key);
    }
}

void PUSH(int n){
    append(n);
    printf("%d\n", n);
}

void POP(){
    if(isEmpty()){
        printf("-1\n");
        return;
    }
    else{
        printf("%d\n", tail -> key);
        delete(length()-1);
    }
}

void SEARCH(int n){
    int loc = -1, len = length();
    Node *now;
    now = calloc(1, sizeof(Node));
    now = head -> next;

    for(int i = len-1; i >= 0; i--){
        if(now -> key == n){
            loc = i;
        }
        now = now -> next;
    }

    free(now);
    printf("%d\n", loc);
}

/* linked list functions */


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