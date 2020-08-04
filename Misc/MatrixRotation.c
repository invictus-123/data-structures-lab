#include<stdio.h>
#include<stdlib.h>
int row, col;
void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void PrintMatrix(int mat[row][col]) {
	for(int i = 0; i < row; i ++) {
		for(int j = 0; j < col; j ++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}
void Transpose(int mat[row][col]) {
	for(int i = 0; i < row; i ++) {
		for(int j = i; j < col; j ++) {
			swap(&mat[i][j], &mat[j][i]);
		}
	}
}
void Reverse(int mat[row][col]) {
	for(int i = 0; i < row; i ++) {
		for(int j = 0, k = col - 1; j < k; j ++, k --) {
			swap(&mat[i][j], &mat[i][k]);
		}
	}
}
void Rotate(int mat[row][col]) {
	Transpose(mat);
	Reverse(mat);
}
int main() {
	printf("Enter the order of the matrix : ");
	scanf("%d%d", &row, &col);
	int mat[row][col];
	printf("Enter the elements of the matrix : ");
	for(int i = 0; i < row; i ++) {
		for(int j = 0; j < col; j ++) {
			scanf("%d", &mat[i][j]);
		}
	}
	PrintMatrix(mat);
	Rotate(mat);
	PrintMatrix(mat);
	return 0;
}

