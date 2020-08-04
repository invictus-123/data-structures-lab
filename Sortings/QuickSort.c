#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
int Partition(int arr[], int lo, int hi) {
	int pivot = lo, l = lo, r = hi;
	while(l < r) {
		while(arr[l] <= arr[pivot]) {
			l ++;
		}
		while(arr[r] > arr[pivot]) {
			r --;
		}
		if(l < r) {
			swap(&arr[l], &arr[r]);
		}
	}
	swap(&arr[lo], &arr[r]);
	return r;
}
void QuickSort(int arr[], int l, int r) {
	if(l < r) {
		int p = Partition(arr, l, r);
		QuickSort(arr, l, p - 1);
		QuickSort(arr, p + 1, r);
	}
}
int main() {
	int n = 10;
	int arr[10];
	for(int i = 0; i < 10; i ++) {
		arr[i] = rand() % 100;
	}
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	QuickSort(arr, 0, n - 1);
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

