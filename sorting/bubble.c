#include<stdio.h>

void bubblesort(int *arr, int n) {
	int temp;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n-i; j++) {
			if(arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
int main() {
	int arr[5] = {2, 45 ,657,34,5};
	int size = sizeof(arr)/sizeof(int);
	bubblesort(arr, size);
	for(int i=0; i<size; i++) {
		printf("%d\t", arr[i]);
	}
	return 0;
}
