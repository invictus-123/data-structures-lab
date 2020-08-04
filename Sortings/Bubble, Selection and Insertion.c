#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void BubbleSort(int *arr, int n) {
	int swaps;
	for(int i = 0; i < n; i ++) {
		swaps = 0;
		for(int j = 0; j < n - i - 1; j ++) {
			if(arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swaps ++;
			}
		}
		if(swaps == 0) {
			return;
		}
	}
}
void SelectionSort(int *arr, int n) {
	int mn, idx;
	for(int i = 0; i < n - 1; i ++) {
		mn = arr[i], idx = i;
		for(int j = i + 1; j < n; j ++) {
			if(arr[j] < mn) {
				mn = arr[j];
				idx = j;
			}
		}
		swap(&arr[i], &arr[idx]);
	}
}
void InsertionSort(int *arr, int n) {
	for(int i = 1; i < n; i ++) {
		int j = i;
		while(j > 0 && arr[j] < arr[j - 1]) {
			swap(&arr[j], &arr[j - 1]);
			j --;
		}
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
	// Uncomment one of the following to use corresponding sorting algorithm
	// BubbleSort(arr, n);
	// SelectionSort(arr, n);
	// InsertionSort(arr, n);
	printf("The sorted array is : ");
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

