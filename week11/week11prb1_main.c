#include <stdio.h>
#include <stdlib.h>


/* data structure */
typedef struct node {
	int key;
	struct node *next;
} Node;

/* external functions */
int isEmpty(void);
int length(void);
void clear(void);
void insert(int key, int loc);
void append(int key);
void delete(int loc);

/* global variables */
Node *head, *tail;

/* print_list */
void print_list(void)
{
	if (isEmpty()) {
		puts("empty");
		return;
	}

	for (Node *node = head->next; node; node = node->next)
		printf("%d ", node->key);

	puts("");
}

/* main */
int main(void)
{
	int op;
	int key, loc;

	/* initialize */
	head = tail = calloc(1, sizeof(Node));

	/* operation */
	while (1) {
		if ((op = getchar()) == EOF)
			break;

		switch (op) {
		case 'C':
			clear();
			break;
		case 'I':
			scanf("%d %d", &key, &loc);
			insert(key, loc);
			break;
		case 'A':
			scanf("%d", &key);
			append(key);
			break;
		case 'D':
			scanf("%d", &loc);
			delete(loc);
			break;
		case 'P':
			print_list();
			break;
		}
	}

	/* deinitialize */
	clear();
	free(head);
	return 0;
}

