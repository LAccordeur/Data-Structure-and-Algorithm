#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node LNode;
typedef struct Node *LinkedList;

LinkedList CycLinkedListCreate(int length,int a[])
{
	LinkedList L,tail;
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL){
		printf("Failed to apply the space!");
		exit(0);
	}

	L -> next = L;
	tail = L;

	int i;
	for (i = 0;i < length;i++){
		LinkedList p;
		p = (LNode *)malloc(sizeof(LNode));
		if (p == NULL){
			printf("Failed to apply the space!");
			exit(0);
		}

		p -> data = a[i];
		p -> next = L;
		tail -> next = p;
		tail = p;
	}

	return L;
}

void CycLinkedListDelete(LinkedList L,int e)
{
	LinkedList pre;
	pre = L;
	while((pre -> next != L) && (pre -> next -> data != e)){
		pre = pre -> next;
	}
	LinkedList p;
	p = pre -> next;

	if (p != L){
		pre -> next = p -> next;
		free(p);
	}
}

LinkedList CycLinkedListLocate(LinkedList L, int e)
{
	LinkedList p;
	p = L -> next;
	while ((p != L) && (p -> data != e)){
		p = p -> next;
	}
	return p;

}

void CycLinkedListInsert(LinkedList L,LinkedList p,int e)
{
	LinkedList q;
	q = (LNode *)malloc(sizeof(LNode));
	if (q = NULL){
		printf("Failed to apply the space!");
	}

	q -> data = e;
	
	LinkedList pre;
	pre = L;
	while ((pre != L) && pre -> next != p){
		pre = pre -> next;
	}

	q -> next = pre -> next;
	pre -> next = q;
}

bool CycLinkedListIsempty(LinkedList L)
{
	if (L -> next == L){
		return true;
	}else{
		return false;
	}
}

void CycLinkedListClear(LinkedList L)
{
	if (L -> next == L){
		printf("This list has been empty");
	}

	LinkedList pre,pre0;
	pre = L;
	pre0 = L;
	while((pre -> next) != L){
		pre = pre -> next;
		pre0 = pre -> next;
		free (pre);
		pre = pre0;
	}
}

void PrintList(LinkedList L)
{
	LinkedList pre;
	pre = L;
	while(pre -> next != L){
		printf("%d  ",pre -> next -> data);
		pre = pre -> next;
	}
}

int main(void){
	int i,length,a[length];
	printf("Enter the length of the list: ");
	scanf("%d",&length);
	printf("Enter the elements(integer) of the list: ");
	for (i = 0;i < length;i++){
		scanf(" %d",&a[i]);
	}

	LinkedList SL;
	SL = CycLinkedListCreate(length,a);

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
					CycLinkedListDelete(SL,e0);
					PrintList(SL);
					break;
			case 2: printf("Enter the element you want to Insert: ");
					int e;
					LinkedList q;
					scanf("%d",e);
					q = CycLinkedListLocate(SL,e);
					CycLinkedListInsert(SL,q,e);
					PrintList(SL);
					break;
			case 3: if (CycLinkedListIsempty(SL)){
						printf("The list is empty.");
					}else{
						printf("The list isn't empty.");
					}
					break;
			case 4: CycLinkedListClear(SL);
					break;
			default:printf("The value you entered is illegal!");
					break;		
		}
	}while(choice != 0)

	


}