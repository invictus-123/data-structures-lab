#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
struct queue {
	int front, back;
	node *arr[100];
} q;
void EnQueue(node *cur) {
	if(q.front == -1) {
		q.front = q.back = 0;
		q.arr[0] = cur;
	}
	else {
		q.arr[++ q.back] = cur;
	}
}
node *DeQueue() {
	node *temp = q.arr[q.front ++];
	if(q.front > q.back) {
		q.front = q.back = -1;
	}
	return temp;
}
int isEmpty() {
	return q.front == -1;
}
node *NewNode(int val) {
	node *temp = (node *) malloc(sizeof(node));
	temp->data = val;
	temp->left = temp->right = NULL;
	return temp;
}
void LevelOrder(node *root) {
	EnQueue(root);
	node *temp;
	while(!isEmpty()) {
		temp = DeQueue();
		printf("%d ", temp->data);
		if(temp->left != NULL) {
			EnQueue(temp->left);
		}
		if(temp->right != NULL) {
			EnQueue(temp->right);
		} 
	}
	printf("\n");
}
void InOrder(node *cur) {
	if(cur) {
		InOrder(cur->left);//InOrder((*cur).left);
		printf("%d ", cur->data);
		InOrder(cur->right);
	}
}
int main() {
	q.front = -1;
	q.back = -1;
	/*
	          5
		/   \
	      10     11
	     /  \   /  
	    20  21 22
	            \
	             30
	*/
	node *root = NewNode(5);
	root->left = NewNode(10);
	root->right = NewNode(11);
	root->left->left = NewNode(20);
	root->left->right = NewNode(21);
	root->right->left = NewNode(22);
	root->right->left->right = NewNode(30);
	InOrder(root);
	printf("\n");
	LevelOrder(root);
	return 0;
}

