#include<stdio.h>
#include<stdlib.h>
int row, col;
void Spiral(int mat[row][col]) {
	int sr = 0, sc = 0, er = row - 1, ec = col - 1, d = 0;
	while(sr <= er && sc <= ec) {
		if(d == 0) {
			for(int i = sc; i <= ec; i ++) {
				printf("%d ", mat[sr][i]);
			}
			sr ++;
		}
		else if(d == 1) {
			for(int i = sr; i <= er; i ++) {
				printf("%d ", mat[i][ec]);
			}
			ec --;
		}
		else if(d == 2) {
			for(int i = ec; i >= sc; i --) {
				printf("%d ", mat[er][i]);
			}
			er --;
		}
		else {
			for(int i = er; i >= sr; i --) {
				printf("%d ", mat[i][sc]);
			}
			sc ++;
		}
		d = (d + 1) % 4;
	}
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
	Spiral(mat);
	return 0;
}

