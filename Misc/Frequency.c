#include<stdio.h>
#include<stdlib.h>
int main() {
	int n, k;
	printf("Enter the number of elements and value of k : ");
	scanf("%d%d", &n, &k);
	int *A = (int *) malloc (sizeof(int) * n);
	printf("Enter the elements : ");
	for(int i = 0; i < n; i ++) {
		scanf("%d", &A[i]);
	}
	int *freq = (int *) malloc (sizeof(int) * (k + 1));
	for(int i = 0; i < n; i ++) {
		freq[A[i]] ++;
	}
	for(int i = 1; i <= k; i ++) {
		printf("Frequency of %d is : %d\n", i, freq[i]);
	}
	return 0;
}

