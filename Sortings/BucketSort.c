#include<stdio.h>
#include<stdlib.h>
void swap(float *a, float *b) {
	float t = *a;
	*a = *b;
	*b = t;
}
void BucketSort(float arr[], int n) {
	float brr[10][n];
	int idx[10];
	for(int i = 0; i < 10; i ++) {
		idx[i] = 0;
	}
	for(int i = 0; i < n; i ++) {
		int temp = (int)(arr[i] * 10);
		brr[temp][idx[temp]] = arr[i];
		int j = idx[temp];
		while(j > 0 && brr[temp][j] < brr[temp][j - 1]) {
			swap(&brr[temp][j - 1], &brr[temp][j]);
			j --;
		}
		idx[temp] ++;
	}
	int i = 0;
	for(int j = 0; j < 10; j ++) {
		for(int k = 0; k < idx[j]; k ++) {
			arr[i ++] = brr[j][k];
		}
	}
}
int main() {
	int n = 10;
	float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.121, 0.23, 0.68};
	for(int i = 0; i < n; i ++) {
		printf("%f ", arr[i]);
	}
	printf("\n");
	BucketSort(arr, n);
	for(int i = 0; i < n; i ++) {
		printf("%f ", arr[i]);
	}
	printf("\n");
	return 0;
}

