/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
void Modify(node **head, int K);
struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL && K<0)
		return NULL;

	struct node *p = head;

	Modify(&p, K);
	return p;

}
void Modify(node **head, int K){
	if (*head == NULL) return;

	int pos = 0;
	node *p, *q = NULL;
	node *newnode = (node*)malloc(sizeof(node));
	newnode->num = K;
	p = *head;
	if (K == 0){
		newnode->next = p;
		*head = newnode;
	}
	else{
		while ((p != NULL) && (pos<K))
		{
			pos++;
			q = p;
			p = p->next;
			if (p == NULL  & K != 1) return;
		}
		q->next = newnode;
		newnode->next = p;
	}
	Modify(&newnode->next, K);
}
