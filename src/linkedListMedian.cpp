/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	//init checking
	if (head == NULL)
		return -1;

	struct node *p1, *p2;
	p1 = p2 = head;
	int i = 0;

	//checking for 1
	if (p1->next == NULL) return p1->num;
	//checking for 2 
	if (p1->next->next == NULL) return (p1->num + p1->next->num) / 2;

	while (p1->next != NULL){
		if (i == 0){
			p1 = p1->next;
			i = 1;
		}
		else if (i == 1){
			p1 = p1->next;
			p2 = p2->next;
			i = 0;
		}
	}

	if (i == 1)
		return (p2->num + p2->next->num) / 2;
	else
		return p2->num;

}
