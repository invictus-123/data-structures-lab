#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void MaxHeapify(int *arr, int i, int n) {
	int l = 2 * i + 1, r = 2 * i + 2, largest = i;
	if(l < n && arr[l] > arr[largest]) {
		largest = l;
	}
	if(r < n && arr[r] > arr[largest]) {
		largest = r;
	}
	if(largest != i) {
		swap(&arr[i], &arr[largest]);
		MaxHeapify(arr, largest, n);
	}
}
void HeapSort(int *arr, int n) {
	for(int i = n / 2 - 1; i >= 0; i --) {
		MaxHeapify(arr, i, n);
	}
	for(int i = n - 1; i >= 0; i --) {
		swap(&arr[0], &arr[i]);
		MaxHeapify(arr, 0, i);
	}
}
int main() {
	int n;
	printf("Enter number of elements : ");
	scanf("%d", &n);
	int *arr = (int *) malloc (sizeof(int) * n);
	printf("Enter the elements : ");
	for(int i = 0; i < n; i ++) {
		scanf("%d", &arr[i]);
	}
	HeapSort(arr, n);
	printf("The sorted array is : ");
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

