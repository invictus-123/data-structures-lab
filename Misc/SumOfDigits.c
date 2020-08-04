#include<stdio.h>
#include<stdlib.h>
int sumofdigits(int n) {
	if(n == 0) {
		return 0;
	}
	return n % 10 + sumofdigits(n / 10);
} 
int main() {
	int n;
	printf("Enter a numbers : ");
	scanf("%d", &n);
	printf("Sum of digits of %d is : %d\n", n, sumofdigits(n));
	return 0;
}

