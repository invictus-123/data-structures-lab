#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
struct Node * NewNode(int val) {
	struct Node *temp = (struct Node *) malloc (sizeof(struct Node));
	temp->data = val;
	temp->next = NULL;
	return temp;
}
void InsertionAtFront(struct Node *head, int val) {
	struct Node* new = NewNode(val);
	new->next = head->next;
	head->next = new;
}
void InsertionAtEnd(struct Node *head, int val) {
	struct Node *new = NewNode(val);
	struct Node *cur = head;
	while(cur->next) {
		cur = cur->next;
	}
	cur->next = new;
}
void InsertionBeforeNode(struct Node *head, int val, int target) {
	struct Node *new = NewNode(val);
	struct Node *cur = head;
	while(cur->next) {
		if(cur->next->data == target) {
			break;
		}
		cur = cur->next;
	}
	new->next = cur->next;
	cur->next = new;
}
void InsertionAfterNode(struct Node *head, int val, int target) {
	struct Node *new = NewNode(val);
	struct Node *cur = head->next;
	while(cur) {
		if(cur->data == target) {
			break;
		}
		cur = cur->next;
	}
	new->next = cur->next;
	cur->next = new;
}
void Delete(struct Node *head, int val) {
	struct Node *cur = head;
	while(cur->next) {
		if(cur->next->data == val) {
			break;
		}
		cur = cur->next;
	}
	cur->next = cur->next->next;
}
void Print(struct Node *head) {
	struct Node *cur = head->next;
	while(cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
int main() {
	struct Node *head = (struct Node *) malloc (sizeof(struct Node));
	InsertionAtEnd(head, 10);
	InsertionAtEnd(head, 5);
	Print(head);
	InsertionAtFront(head, 7);
	InsertionAtFront(head, 5);
	InsertionBeforeNode(head, 11, 7);
	Print(head);
	return 0;
}

