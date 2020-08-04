#include<stdio.h>
#include<stdlib.h>
int numberofdigits(int n) {
	if(n == 0) {
		return 0;
	}
	return 1 + numberofdigits(n / 10);
} 
int main() {
	int n;
	printf("Enter a numbers : ");
	scanf("%d", &n);
	printf("Number of digits in %d is : %d\n", n, numberofdigits(n));
	return 0;
}

