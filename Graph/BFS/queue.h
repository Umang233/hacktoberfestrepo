
typedef struct node {
	int value;
	struct node *next;
}node;

typedef struct queue {
	node *front, *rear;
}queue;




void qinit(queue *q);
void enq(queue *q, int a);
int deq(queue *q);
int qfull(queue *q);
int qempty(queue *q);
void display(queue *q);
