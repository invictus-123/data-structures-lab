#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};
struct node * NewNode(int val) {
	struct node *new = (struct node *) malloc(sizeof(struct node));
	new->data = val;
	new->next = NULL;
	new->prev = NULL;
	return new;
}
void InsertionAtFirst(struct node *head, int val) {
	struct node *new = NewNode(val);
	struct node *temp = head->next;
	new->prev = head;
	head->next = new;
	if(temp) {
		temp->prev = new;
		new->next = temp;
	}
}
void InsertionAtLast(struct node *head, int val) {
	struct node *new = NewNode(val);
	struct node *cur = head;
	while(cur->next) {
		cur = cur->next;
	}
	new->prev = cur;
	cur->next = new;
}
void InsertionAfterNode(struct node *head, int val, int target) {
	//Assuming target value exists in the list
	struct node *new = NewNode(val);
	struct node *cur = head->next;
	while(cur->data != target) {
		cur = cur->next;
	}
	struct node *temp = cur->next;
	cur->next = new;
	new->prev = cur;
	if(temp) {
		new->next = temp;
		temp->prev = new;
	}
}
void InsertionBeforeNode(struct node *head, int val, int target) {
	//Assuming target value exists in the list
	struct node *new = NewNode(val);
	struct node *cur = head->next;
	while(cur->data != target) {
		cur = cur->next;
	}
	struct node *temp = cur;
	cur = cur->prev;
	cur->next = new;
	new->prev = cur;
	new->next = temp;
	temp->prev = new;
}
void Delete(struct node *head, int val) {
	//Assuming value exists in the list
	struct node *cur = head->next;
	while(cur->data != val) {
		cur = cur->next;
	}
	struct node *temp1 = cur->prev;
	struct node *temp2 = cur->next;
	temp1->next = temp2;
	if(temp2) {
		temp2->prev = temp1;
	}
}
void Print(struct node *head) {
	struct node *cur = head->next;
	while(cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void PrintReverse(struct node *head) {
	struct node *cur = head;
	while(cur->next) {
		cur = cur->next;
	}
	while(cur != head) {
		printf("%d ", cur->data);
		cur = cur->prev;
	}
	printf("\n");
}
int main() {
	struct node *head = (struct node *) malloc (sizeof(struct node));
	head->next = NULL;
	head->prev = NULL;
	InsertionAtFirst(head, 5);
	Print(head);
	PrintReverse(head);
	InsertionAtFirst(head, 10);
	Print(head);
	PrintReverse(head);
	InsertionAtLast(head, 7);
	Print(head);
	PrintReverse(head);
	InsertionAtLast(head, 11);
	Print(head);
	PrintReverse(head);
	Delete(head, 11);
	Print(head);
	PrintReverse(head);
	Delete(head, 5);
	Print(head);
	PrintReverse(head);
	InsertionAfterNode(head, 11, 10);
	Print(head);
	PrintReverse(head);
	InsertionAfterNode(head, 14, 7);
	Print(head);
	PrintReverse(head);
	InsertionBeforeNode(head, 20, 14);
	Print(head);
	PrintReverse(head);
	InsertionBeforeNode(head, 32, 10);
	Print(head);
	PrintReverse(head);
	return 0;
}

