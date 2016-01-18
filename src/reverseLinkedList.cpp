/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void Reverse(struct node **head);
struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	else{
		Reverse(&head);
		return head;
	}

}
void Reverse(struct node **head_ref)
{
	struct node* first;
	struct node* rest;

	if (*head_ref == NULL)
		return;

	first = *head_ref;
	rest = first->next;


	if (rest == NULL)
		return;

	Reverse(&rest);
	first->next->next = first;


	first->next = NULL;

	*head_ref = rest;
}