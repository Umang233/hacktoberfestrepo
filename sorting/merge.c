#include<stdio.h>

void merge(int *arr, int l, int m, int r) {
	int n1, n2;
	n1 = m-l+1;
	n2 = r-m;
	int L[n1], R[n2];
	for(int i=0; i<n1; i++) {
		L[i] = arr[l+i];
	}
	for(int i=0; i<n2; i++) {
		R[i] = arr[m+1+i];
	} 
 	
 	int i=0, j=0, k=l;
 	while(i<n1 && j<n2) {
 		if(L[i]<=R[j]) {
 			arr[k] = L[i];
 			i++;
 			k++;
 		}
 		else {
 			arr[k] = R[j];
 			j++;
 			k++;
 		}
 	}
 	
	while(i<n1) {
 		arr[k] = L[i];
 		i++;
 		k++;
 	}
	while(j<n2) {
 		arr[k] = R[j];
 		j++;
 		k++;
 	}
}


void mergesort(int *arr, int l, int r) {
	if (l<r) {
	
		int m = (l+r)/2;
		mergesort(arr, l, m);
		mergesort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}


int main() {
	int arr[5] = {2, 5, 3, 78, 34};
	int size = sizeof(arr)/sizeof(int);
	mergesort(arr, 0, size-1);
	for (int i=0; i<size; i++) {
		printf("%d\t", arr[i]);
	}
	return 0;
}







