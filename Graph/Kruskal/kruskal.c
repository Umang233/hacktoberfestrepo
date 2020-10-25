#include<stdio.h>
#include<stdlib.h>

typedef struct graph {
	int n;
	int **a;
}graph;

typedef struct edge {
	int s,d, edgew;
}edge;

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

void sort(edge *e, int count) {
	edge temp;
	for(int j=0; j<count; j++) {
		for(int i=j+1; i<count-j; i++) {
			if(e[j].edgew > e[i].edgew) {
				temp = e[j];
				e[j] = e[i];
				e[i] = temp;
			}
		}	
	}
}

graph kruskal(graph *g) {
	int *visited, a = 0, count;
	edge *e;
	graph k;
	k.n = g->n;
	k.a = (int **)malloc(sizeof(int *) * g->n);
	if(k.a == NULL) {
		fprintf(stderr, "No Memory\n");
		exit(0);
	}
	for(int i=0; i<k.n; i++) {
		k.a[i] = (int *)calloc(g->n, sizeof(int));
		if(k.a[i] == NULL) {
			fprintf(stderr, "No Memory\n");
			exit(0);
		}
	}
	visited = (int *)malloc(sizeof(int) * g->n);
	if(visited == NULL) {
		fprintf(stderr, "No Memory\n");
		exit(0);
	}
	for(int i=0; i<g->n; i++) {
		visited[i] = 0;
	}
	for(int i=0; i<g->n; i++) {
		for(int j=0; j<g->n; j++) {
			if(g->a[i][j])
				count++;
		}
	}
	e = (edge *)malloc(sizeof(edge) * count);
	if(e == NULL) {
		fprintf(stderr, "No Memory\n");
		exit(0);
	}
	for(int i=0; i<g->n; i++) {
		for(int j=0; j<g->n; j++) {
			if(!visited[i] && g->a[i][j]) {
				e[a].s = i;
				e[a].d = j;
				e[a].edgew = g->a[i][j];
				visited[a] = 1;
				a++;
			}
		}
	}
	sort(e, count);
	for(int i=0; i<g->n; i++) {
		visited[i] = 0;
	}
	for(int i=0; i<count; i++) {
		if(!visited[e[i].s] || !visited[e[i].d]) {
			k.a[e[i].s][e[i].d] = e[i].edgew;
			visited[e[i].s] = 1;
			visited[e[i].d] = 1;
		}
	}
	return k;
}

int main(int argc, char *argv[]) {
	graph g, k;
	initgraph(&g, argv[1]);
	k = kruskal(&g);
	for(int i=0; i<getn(&g); i++) {
		for(int j=0; j<getn(&g); j++) {
			printf("%4d", k.a[i][j]);
		}
		printf("\n");
	}
	return 0;
}

