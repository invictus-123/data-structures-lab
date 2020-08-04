#include<stdio.h>
#include<stdlib.h>
void Merge(int arr[], int st, int en) {
	int mid = (st + en) / 2;
	int left[mid - st + 1], right[en - mid];
	for(int i = st; i <= en; i ++) {
		if(i <= mid) {
			left[i - st] = arr[i];
		}
		else {
			right[i - mid - 1] = arr[i];
		}
	}
	int l = 0, r = 0, idx = st;
	while(l < mid - st + 1 && r < en - mid) {
		if(left[l] < right[r]) {
			arr[idx ++] = left[l ++];
		}
		else {
			arr[idx ++] = right[r ++];
		}
	}
	while(l < mid - st + 1) {
		arr[idx ++] = left[l ++];
	}
	while(r < en - mid) {
		arr[idx ++] = right[r ++];
	}
}
void MergeSort(int arr[], int st, int en) {
	if(st >= en) {
		return;
	}
	int mid = (st + en) / 2;
	MergeSort(arr, st, mid);
	MergeSort(arr, mid + 1, en);
	Merge(arr, st, en);
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
	MergeSort(arr, 0, n - 1);
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

