
typedef struct node {
	char name[16];
	unsigned int old;
	struct node *next;
}node;

typedef struct queue {
	node *front, *rear;
}queue;

void qinit(queue *q) {
	q->front = NULL;
	q->rear = NULL;
}

void qinit(queue *q);
void enq(queue *q, char *str, age a);
int deq(queue *q);
int qfull(queue *q);
int qempty(queue *q);
