#include<stdio.h>
#include<stdlib.h>
long long bin(int n) {
	int ans = 0, base = 1;
	while(n > 0) {
		ans = ans + (n % 2) * base;
		n /= 2;
		base *= 10;
	}
	return ans;
}
int dec(long long n) {
	int ans = 0, base = 1;
	while(n > 0) {
		ans = ans + (n % 10) * base;
		base *= 2;
		n /= 10;
	}
	return ans;
}
int main() {
	int choice;
	printf("Enter 1 for Decimal to Binary or 2 for Binary to Decimal : ");
	scanf("%d", &choice);
	if(choice == 1) {
		int n;
		printf("Enter the decimal number : ");
		scanf("%d", &n);
		printf("Binary of %d is : %lld\n", n, bin(n));
	}
	else {
		long long n;
		printf("Enter the binary number : ");
		scanf("%lld", &n);
		printf("Decimal of %lld is : %d\n", n, dec(n));
	}
	return 0;
}

