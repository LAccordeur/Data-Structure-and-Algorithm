#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

typedef struct Node
{
	int data;
	struct Node *next,*prior;
};
typedef struct Node DLNode;
typedef struct Node *DLinkedList;

DLinkedList DLinkedListCreate(int length,int a[])
{
	DLinkedList L;
	L = (DLNode *)malloc(sizeof(DLNode));
	if (L == NULL){
		printf("Failed to apply the space!");
		exit(0);
	}
	L -> next = L;
	L -> prior = L;
	
	int i;
	DLinkedList tail;
	tail = L;
	for (i = 0;i < length; i++){
		DLinkedList p;
		p = (DLNode *)malloc(sizeof(DLNode));
		if (p == NULL){
			printf("Failed to apply the space!");
			exit(0);
		}

		p -> data = a[i];
		p -> prior = tail;
		tail -> next = p;
		p -> next = L;
		L -> prior = p;
		tail = tail -> next;
	}
}

void DLinkedListDelete(DLinkedList L,int e)
{
	p = L -> next;
	while ((p != L) && (p -> data != e)){
		p = p -> next;
	}

	if (p != L){
		p -> prior -> next = p -> next;
		p -> next -> prior = p -> prior;
		free(p);
	}
}

DLinkedList DLinkedListLocate(DLinkedList L, int e)
{
	DLinkedList p;
	p = L -> next;
	while  ((p != L) && (p -> data != e)){
		p = p -> next;
	}
	return p;
}

void DLinkedListInsert(DLinkedList L, DLinkedList p, int e)
{
	DLinkedListInsert q;
	q = (DLNode *)malloc(sizeof(DLNode));

	q -> data = e;
	if (q == NULL){
		printf("Failed to apply the space!");
		exit(0);
	}

	q -> prior = p -> prior;
	p -> prior -> next = q;
	q -> next = p;
	p -> prior = q;
}

bool DLinkedListIsempty(DLinkedList L)
{
	if (L -> next == L && L ->prior == L){
		return true;
	}else{
		return false;
	}
}

void DLinkedListClear(DLinkedList L)
{
	DLinkedList q,p = L -> next;
	while (p != L){
		q = p -> next;
		free(p);
		p = q;
	}

	L -> next = L;
	L -> prior = L;
}

void PrintList(DLinkedList L)
{
	DLinkedList pre;
	pre = L;
	while(pre -> next != L){
		printf("%d  ",pre -> next -> data);
		pre = pre -> next;
	}
	printf("\n\n");
}


int main(void){
	int i,length,a[MAXSIZE];
	printf("Enter the length of the list: ");
	scanf("%d",&length);
	printf("Enter the elements(integer) of the list: ");
	for (i = 0;i < length;i++){
		scanf(" %d",&a[i]);
	}

	DLinkedList SL;
	SL = DLinkedListCreate(length,a);

	printf("\n");
	printf("Delete an element == 1\n");
	printf("Insert an element == 2\n");
	printf("Is empty or not == 3\n");
	printf("Clear this list == 4\n");
	printf("Exit == 0\n\n");

	int choice;
	do{
		printf("Enter your choice:");
		scanf(" %d",&choice);

		switch(choice){
		case 1: printf("Enter the element you want to delete: ");
			int e0;
			scanf("%d",&e0);
			DLinkedListDelete(SL,e0);
			PrintList(SL);
			break;
		case 2: int e,e1;
			printf("Enter the value you want to Insert: ");
			scanf(" %d",&e1);
			printf("Which element's location you want to insert:");
			scanf(" %d",&e);
			LinkedList q;

			q = DLinkedListLocate(SL,e);
			DLinkedListInsert(SL,q,e1);
			PrintList(SL);
			break;
		case 3: if (DLinkedListIsempty(SL)){
			printf("The list is empty.\n\n");
				}else{
					printf("The list isn't empty.\n\n");
				}
				break;
		case 4: DLinkedListClear(SL);
			break;
		default:
			break;		
		}
	}while(choice != 0);

	return 0;

}