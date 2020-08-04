#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct stack {
	int top;
	struct node *arr[100];
} st;
typedef struct node node;
void Push(node *cur) {
	st.arr[++ st.top] = cur;
}
node *Pop() {
	return st.arr[st.top --];
}
int IsEmpty() {
	return st.top == -1;
}
node *NewNode(int val) {
	node *temp = (node *) malloc (sizeof(node));
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}
node *Insert(node *cur, int val) {
	if(cur == NULL) {
		return NewNode(val);
	}
	if(val < cur->data) {
		cur->left = Insert(cur->left, val);
	}
	else {
		cur->right = Insert(cur->right, val);
	}
	return cur;
}
void InOrderRec(node *cur) {
	if(cur) {
		InOrderRec(cur->left);
		printf("%d ", cur->data);
		InOrderRec(cur->right);
	}
}
void InOrderIter(node *root) {
	node *cur = root;
	while(cur != NULL || !IsEmpty()) {
		while(cur != NULL) {
			Push(cur);
			cur = cur->left;
		}
		cur = Pop();
		printf("%d ", cur->data);
		cur = cur->right;
	}
}
int main() {
	st.top = -1;
	int n;
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	node *root = NULL;
	printf("Enter the values : ");
	for(int i = 0; i < n; i ++) {
		int x;
		scanf("%d", &x);
		root = Insert(root, x);
	}
	InOrderRec(root);
	printf("\n");
	InOrderIter(root);
	printf("\n");
	return 0;
}

