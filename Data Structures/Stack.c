#include<stdio.h>
#include<stdlib.h>
struct Stack {
	int top, size;
	int arr[20];
} st;
int IsFull() {
	return st.top == st.size - 1;
}
int IsEmpty() {
	return st.top == -1;
}
void Push(int val) {
	if(IsFull()) {
		printf("The Stack is full!\n");
		return;
	}
	st.arr[++ st.top] = val;
}
void Pop() {
	if(IsEmpty()) {
		printf("The Stack is empty!\n");
		return;
	}
	st.top --;
}
int Top() {
	if(IsEmpty()) {
		return -1;
	}
	return st.arr[st.top];
}
int main() {
	int n;
	printf("Enter the size of stack : ");
	scanf("%d", &n);
	st.top = -1;
	st.size = n;
	st.arr = (int *) malloc (sizeof(int) * n);
	Push(10);
	printf("%d\n", Top());
	Push(20);
	printf("%d\n", Top());
	Pop();
	printf("%d\n", Top());
	return 0;
}

