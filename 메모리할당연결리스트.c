#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL){
    	printf("새 노드 할당에 실패했습니다.\n");
    	exit(0);
	} 
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void appendNode(Node** head, int data){
	Node* newNode = createNode(data);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	
	Node* current = *head;
	while(current->next != NULL){
		current = current -> next;
	}
	
	current -> next = newNode;
}

void printList(Node* head){
	
	Node* current = head;
	while(current != NULL){
		printf("%d ", current -> data);
		current = current -> next;
	}
	printf("\n");
}

void freeList(Node *head){
	Node* temp;
	while(head != NULL){
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main(void){
	Node* head = NULL;
	
	appendNode(&head, 10);
	appendNode(&head, 20);
	appendNode(&head, 30);
	
	printf("연결 리스트: ");
	printList(head);
	
	freeList(head);
	
	return 0;
}
