/*
OVERVIEW: Merge two sorted nexted lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
void append(struct node **q, int num)
{
	struct  node *temp, *r;

	if (*q == NULL)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->num = num;
		temp->next = NULL;
		*q = temp;

	}
	else
	{
		temp = *q;
		while (temp->next != NULL)
			temp = temp->next;
		r = (struct node *)malloc(sizeof(struct node));
		r->num = num;
		r->next = NULL;
		temp->next = r;


	}
}
struct node * Merge(struct node **l1, struct node **l2);
struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else if (head1 == NULL && head2 == NULL) return NULL;

	return Merge(&head1, &head2);
}
struct node * Merge(struct node **l1, struct node **l2){
	struct node *p1, *p2, *finish, *headfinsh;

	finish = NULL;
	p1 = *l1;
	p2 = *l2;
	int flag = 0;

	//Init pointing to lowest value 
	if (p1->num < p2->num){
		finish = p1;
		headfinsh = finish;
		p1 = p1->next;
	}
	else {
		finish = p2;
		headfinsh = finish;
		p2 = p2->next;
	}

	while (1){
		if (p1 == NULL || p2 == NULL) break;
		if (p1->num > p2->num){
			finish->next = p2;
			finish = finish->next;
			p2 = p2->next;
			if (p2 == NULL) break;
		}
		else if (p1->num == p2->num){
			finish->next = p1;
			finish = finish->next;
			p1 = p1->next;
			finish->next = p2;
			finish = finish->next;
			p2 = p2->next;
			/*			finish = finish->next;
			finish = finish->next;*/


			if (p1 == NULL || p2 == NULL) break;
		}
		else{
			finish->next = p1;
			finish = finish->next;
			p1 = p1->next;
			if (p1 == NULL) break;
		}
	}

	if (p1 == NULL){
		finish->next = p2;
	}
	else finish->next = p1;

	//display(headfinsh);
	return headfinsh;
}