#include<stdio.h>
#include<stdlib.h>
int Max(int arr[], int n) {
	int mx = arr[0];
	for(int i = 1; i < n; i ++) {
		if(arr[i] > mx) {
			mx = arr[i];
		}
	}
	return mx;
}
void CountSort(int arr[], int n) {
	int mx = Max(arr, n) + 1;
	int hash[mx], ans[n];
	for(int i = 0; i < mx; i ++) {
		hash[i] = 0;
	}
	for(int i = 0; i < n; i ++) {
		hash[arr[i]] ++;
	}
	for(int i = 1; i < n; i ++) {
		hash[i] = hash[i] + hash[i - 1];
	}
	for(int i = n - 1; i >= 0; i --) {
		ans[hash[arr[i]] - 1] = arr[i];
		hash[arr[i]] --;
	}
	for(int i = 0; i < n; i ++) {
		arr[i] = ans[i];
	}
}
int main() {
	int n = 10;
	int arr[10] = {4, 6, 2, 1, 6, 2, 7, 8, 9, 1};
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	CountSort(arr, n);
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

