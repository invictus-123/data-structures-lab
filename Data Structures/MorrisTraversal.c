#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
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
void Morris(node *root) {
	node *cur = root;
	while(cur != NULL) {
		if(cur->left == NULL) {
			printf("%d ", cur->data);
			cur = cur->right;
		}
		else {
			node *temp = cur->left;
			while(temp->right != NULL && temp->right != cur) {
				temp = temp->right;
			}
			if(temp->right == NULL) {
				temp->right = cur;
				cur = cur->left;
			}
			else {
				temp->right = NULL;
				printf("%d ", cur->data);
				cur = cur->right;
			}
		}
	}
}
int main() {
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
	Morris(root);
	printf("\n");
	return 0;
}

