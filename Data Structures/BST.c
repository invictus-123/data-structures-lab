#include<stdio.h>
#include<stdlib.h>
struct node {
	int val;
	struct node *lchild;
	struct node *rchild;
};
typedef struct node node;
node * NewNode(int val) {
	node *new = (node *) malloc (sizeof(node));
	new->val = val;
	new->lchild = new->rchild = NULL;
	return new;
}
node * Insert(node *cur, int value) {
	if(cur == NULL) {
		return NewNode(value);
	}
	if(cur->val < value) {
		cur->rchild = Insert(cur->rchild, value);
	}
	else {
		cur->lchild = Insert(cur->lchild, value);
	}
	return cur;
}
node * FindMaximum(node *cur) {
	if(cur->rchild == NULL) {
		return cur;
	}
	return FindMaximum(cur->rchild);
}
node * FindMinimum(node *cur) {
	if(cur->lchild == NULL) {
		return cur;
	}
	return FindMinimum(cur->lchild);
}
void Find(node *cur, int val) {
	if(cur == NULL) {
		printf("Not Found.\n");
		return;
	}
	if(cur->val == val) {
		printf("Found.\n");
	}
	else if(cur->val > val) {
		Find(cur->lchild, val);
	}
	else {
		Find(cur->rchild, val);
	}
}
node * Delete(node *cur, int val) {
	if(cur == NULL) {
		return cur;
	}
	if(cur->val > val) {
		cur->lchild = Delete(cur->lchild, val);
	}
	else if(cur->val < val) {
		cur->rchild = Delete(cur->rchild, val);
	}
	else {
		if(cur->lchild == NULL) {
			node *temp = cur->rchild;
			free(cur);
			return temp;
		}
		else if(cur->rchild == NULL) {
			node *temp = cur->lchild;
			free(cur);
			return temp;
		}
		node *temp = FindMaximum(cur->lchild);
		cur->val = temp->val;
		cur->lchild = Delete(cur->lchild, cur->val);
	}
	return cur;
}
void PreOrder(node *cur) {
	if(cur == NULL) {
		return;
	}
	PreOrder(cur->lchild);
	printf("%d ", cur->val);
	PreOrder(cur->rchild);
}
int main() {
	node *head = NULL;
	head = Insert(head, 5);
	head = Insert(head, 7);
	head = Insert(head, 2);
	head = Insert(head, 1);
	head = Insert(head, 10);
	printf("%d\n", FindMaximum(head)->val);
	printf("%d\n", FindMinimum(head)->val);
	Find(head, 5);
	Find(head, 10);
	Find(head, 1);
	Find(head, 6);
	head = Insert(head, 6);
	Find(head, 6);
	head = Delete(head, 5);
	PreOrder(head);
	return 0;
}

