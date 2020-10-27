#include<stdio.h>
//#include<stdlib.h>

void swap(int *arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void selectionsort(int *arr, int n) {
	int min;
	for(int i=0; i<n; i++) {
		min = i;
		for(int j=i+1; j<n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr, i, min);
	}
}
int main() {
	int arr[10] = {23,34,56,231,86,17,2,5,9,2};
	int size = sizeof(arr)/sizeof(int);
	selectionsort(arr, size);
	for (int i=0; i<size; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	return 0;
}
