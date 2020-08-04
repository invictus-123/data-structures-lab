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
void CountSort(int arr[], int n, int exp) {
	int brr[n], hash[10];
	for(int i = 0; i < 10; i ++) {
		hash[i] = 0;
	}
	for(int i = 0; i < n; i ++) {
		hash[(arr[i] / exp) % 10] ++;
	}
	for(int i = 1; i < 10; i ++) {
		hash[i] += hash[i - 1];
	}
	for(int i = n - 1; i >= 0; i --) {
		brr[hash[(arr[i] / exp) % 10] - 1] = arr[i];
		hash[(arr[i] / exp) % 10] --;
	}
	for(int i = 0; i < n; i ++) {
		arr[i] = brr[i];
	}
}
void RadixSort(int arr[], int n) {
	int mx = Max(arr, n);
	for(int exp = 1; mx / exp > 0; exp *= 10) {
		CountSort(arr, n, exp);
	}
}
int main() {
	int n = 10;
	int arr[10] = {4, 60, 62, 1, 621, 2, 7, 8, 9, 1};
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	RadixSort(arr, n);
	for(int i = 0; i < n; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

