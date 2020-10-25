#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct graph {
	int n;
	int **a;
}graph;

typedef struct arrays {
	int *distance, *path;
}arrays;

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

int findminvertex(int *distance, int *visited, int n) {
	int min = INT_MAX, vertex, i;
	for(i=0; i<n; i++) {
		if(!visited[i] && distance[i] < min) {
			min = distance[i];
			vertex = i;
		}
	}
	return vertex;
}

arrays dijkstra(graph *g, int begin) {
	int *visited, *distance, *path, p, newdistance;
	arrays result;
	visited = (int *)malloc(sizeof(int) * g->n);
	distance = (int *)malloc(sizeof(int) * g->n);
	path = (int *)malloc(sizeof(int) * g->n);
	for(int i=0;  i<g->n; i++) {
		visited[i] = 0;
		distance[i] = g->a[begin][i]!=0 ? g->a[begin][i] : INT_MAX;
		path[i] = g->a[begin][i]!=0 ? begin : -1;
	}
	visited[begin] = 1;
	distance[begin] = 0;
	for(int k=0; k<g->n; k++) {
		p = findminvertex(distance, visited, g->n);
		visited[p] = 1;
		for(int j=0; j<g->n; j++) {
			if(!visited[j] && g->a[p][j]) {
				newdistance = distance[p] + g->a[p][j];
				if(distance[j] > newdistance) {
					distance[j] = newdistance;
					path[j] = p;
				}
			}
		}
	}
	result.distance = distance;
	result.path = path;	
	return result;
}

int main(int argc, char *argv[]) {
	graph g;
	arrays result;
	int start;
	scanf("%d", &start);
	initgraph(&g, argv[1]);
	result = djkstra(&g, start);
	for(int i=0; i<getn(&g); i++) {
		printf("%d %d\n", result.distance[i], result.path[i]);
	}
	return 0;
}



