#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"

void enq(queue *q, char *str, unsigned int a) {
	node *temp;
	if(a<0) {
		printf("Error : Age cannot be negative\n");
		return;
	}
	if(q->rear == NULL) {
		temp = (node *)malloc(sizeof(node));
		if(temp == NULL) {
			return;
		}
		strcpy(temp->name, str);
		temp->old = a;
		temp->next = temp;
		q->front = temp;
		q->rear = temp;
	}
	else {
		temp = (node *)malloc(sizeof(node));
		if(temp == NULL) {
			return;
		}
		strcpy(temp->name, str);
		temp->old = a;
		temp->next = q->front;
		q->rear->next = temp;
		q->rear = temp;
	}
}

node deq(queue *q) {
	node temp;
	if(q->front == q->rear) {
		strcpy(temp.name, q->front->name);
		temp.old = q->front->old;
		temp.next = NULL;
		q->front = NULL;
		q->rear = NULL;
	}
	else {
		strcpy(temp.name, q->front->name);
		temp.old = q->front->old;
		temp.next = NULL;
		q->rear->next = q->front->next;
		q->front->next = NULL;
		q->front = q->rear->next;
	}
	return temp;
}

void display(queue *q) {
	node *trav = q->front;
	while(trav != q->rear) {
		printf("%s - %u\n", trav->name, trav->old);
		trav = trav->next;
	}
	printf("%s - %u\n", q->rear->name, q->rear->old);	
}
int qempty(queue *q) {
	if(q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}

int qfull(queue *q) {
	node *temp;
	temp = (node *)malloc(sizeof(node);
	if(temp = NULL) {
		free(temp);
		return 1;
	}
	else {
		free(temp);
		return 0;
	}
}






