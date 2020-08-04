#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack {
	int top;
	char arr[20];
} st;
void Push(char c) {
	st.arr[++ st.top] = c;
}
void Pop() {
	st.top --;
}
char Top() {
	return st.arr[st.top];
}
int isEmpty() {
	return st.top == -1;
}
int isOperand(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
int prec(char c) {
	if(c == '(') {
		return 4;
	}
	if(c == '^') {
		return 3;
	}
	if(c == '*' || c == '/') {
		return 2;
	}
	if(c == '+' || c == '-') {
		return 1;
	}
	return 0;
}
void PostFix(char str[], int n) {
	for(int i = 0; i < n; i ++) {
		if(isOperand(str[i])) {
			printf("%c", str[i]);
		}
		else if(str[i] == ')') {
			while(Top() != '(') {
				printf("%c", Top());
				Pop();
			}
			if(Top() == '(') {
				Pop();
			}
		}
		else {
			while(!isEmpty() && prec(Top()) >= prec(str[i]) && Top() != '(') {
				printf("%c", Top());
				Pop();
			}
			Push(str[i]);
		}
	}
	while(!isEmpty()) {
		printf("%c", Top());
		Pop();
	}
}
int main() {
	printf("Enter a infix expression : ");
	char str[20];
	scanf("%s", str);
	PostFix(str, strlen(str));
	return 0;
}

