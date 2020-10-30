#include<stdio.h>

void insertionsort(int *arr, int n) {
	int key, j;
	for(int i=1; i<n; i++) {
		key = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key) {
			arr[j+1] = arr[j];
			j-=1;
		}
		arr[j+1] = key;
	}
}

int main() {
	int arr[8] = {23,56,2,8,32,9,0,1};
	int size = sizeof(arr)/sizeof(int);
	insertionsort(arr, size);
	for(int i=0; i<size; i++) {
		printf("%d\t", arr[i]);
	}
	return 0;
}
