#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	int value;
	struct node *next;
}node;

typedef struct queue {
	node *front, *rear;
}queue;

void qinit(queue *q) {
	q->front = NULL;
	q->rear = NULL;
}

void enq(queue *q, int a) {
	node *temp;
	if(q->rear == NULL) {
		temp = (node *)malloc(sizeof(node));
		if(temp == NULL) {
			return;
		}
		temp->value = a;
		temp->next = temp;
		q->front = temp;
		q->rear = temp;
	}
	else {
		temp = (node *)malloc(sizeof(node));
		if(temp == NULL) {
			return;
		}
		temp->value = a;
		temp->next = q->front;
		q->rear->next = temp;
		q->rear = temp;
	}
}

int deq(queue *q) {
	node temp;
	if(q->front == q->rear) {
		temp.value = q->front->value;
		temp.next = NULL;
		q->front = NULL;
		q->rear = NULL;
	}
	else {
		temp.value = q->front->value;
		temp.next = NULL;
		q->rear->next = q->front->next;
		q->front->next = NULL;
		q->front = q->rear->next;
	}
	return temp.value;
}

void display(queue *q) {
	node *trav = q->front;
	while(trav != q->rear) {
		printf("%d\n", trav->value);
		trav = trav->next;
	}
	printf("%d\n", q->rear->value);	
}
int qempty(queue *q) {
	if(q->rear) {
		return 0;
	}
	else {
		return 1;
	}
}

int qfull(queue *q) {
	node *temp;
	temp = (node *)malloc(sizeof(node));
	if(temp == NULL) {
		free(temp);
		return 1;
	}
	else {
		free(temp);
		return 0;
	}
}


