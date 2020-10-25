#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"queue.h"


typedef struct graph {
	int n;
	int **a;
}graph;

void initgraph(graph *g, char *filename) {
	FILE *fp;
	fp = fopen(filename, "r");
	if(fp == NULL) {
		fprintf(stderr, "Cannot open the file\n");
		exit(0);
	}
	fscanf(fp, "%d", &(g->n));
	g->a = (int **)malloc(sizeof(int *) * g->n);
	if(g->a == NULL) {
		fprintf(stderr, "No Memory\n");
		exit(0);
	}
	for(int i=0; i<g->n; i++) {
		g->a[i] = (int *)malloc(sizeof(int) * g->n);
		if(g->a[i] == NULL) {
			fprintf(stderr, "No Memory\n");
			exit(0);
		}
		for(int j=0; j<g->n; j++) {
			fscanf(fp, "%d", &(g->a[i][j]));
		}
	}
}

int getn(graph *g) {
	return g->n;
}

void printgraph(graph *g) {
	for(int i=0; i<getn(g); i++) {
		for(int j=0; j<getn(g); j++) {
			printf("%d\t", g->a[i][j]);
		}
	printf("\n");
	}
}

void bfs(graph *g, int begin) {
	queue q;
	int *visited, num;
	visited = (int *)malloc(sizeof(int) * g->n);
	if(visited == NULL) {
		fprintf(stderr, "No memory\n");
		exit(0);
	}
	for(int i=0; i<g->n; i++) {
		visited[i] = 0;
	}
	qinit(&q);
	enq(&q, begin);
	visited[begin] = 1;
	while(!qempty(&q)) {
		num = deq(&q);
		printf("%d\t", num);
		for(int i=0; i<g->n; i++) {
			if(g->a[num][i]!=0 && !visited[i]) {
				enq(&q, i);
				visited[i] = 1;
			}
		}
	}
}



int main(int argc, char *argv[]) {
	graph g;
	initgraph(&g, argv[1]);
	bfs(&g, 1);
	return 0;
}


