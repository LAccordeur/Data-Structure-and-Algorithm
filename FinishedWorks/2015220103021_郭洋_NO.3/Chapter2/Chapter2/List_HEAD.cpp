// List Head
#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
};
typedef struct Node LNode;
typedef struct Node *LinkedList;

LinkedList LinkedListInit(LinkedList L)
{
	L = (LNode *)malloc(sizeof(LNode));
	if(L == NULL){
		printf("Failed in applying for space!");
		exit(0);
	}
	L -> next = NULL;
	return L;
}

int LinkedListLength(LinkedList L)
{
	LNode *p;
	p = L -> next;
	int j = 0;
	while(p != NULL){
		j++;
		p = p -> next;
	}
	return j;
}

LinkedList LinkedListGet(LinkedList L,int i)
{
	LNode *p;
	p = L -> next;
	int j = 1;
	while ((p != NULL) && (j <= i)){
		p = p -> next;
		j++;
	}
	return p;
}

LNode * LinkedListLocate(LinkedList L,int e)
{
	LNode *p;
	p = L -> next;
	int j = 1;
	while((p != NULL) && (p -> data != e)){
		p = p -> next;
	}
	return p;
}

void LinkedListInsert(LinkedList L,LinkedList p,int e)
{
	LNode * q;
	q = (LNode *)malloc(sizeof(LNode));
	if (q == NULL){
		printf("Failed in applying the space!");
		exit(0);
	}
	
	q -> data = e;
	
	LinkedList pre;
	pre = L;
	while((pre != NULL) && (pre -> next != p)){
		pre = pre -> next;
	}
	
	q -> next = pre -> next;
	pre -> next = q;
}

void LinkedListDel(LinkedList L,int e,LinkedList p)
{
	LinkedList pre;
	pre = L;
	while ((pre != NULL) && (pre -> next -> data != e)){
		pre = pre -> next;
	}
	p = pre -> next;
	
	if (p != NULL){
		pre -> next = p -> next;
		free(p);
	}
}

LinkedList LinkedListCreate(LinkedList L,int a[],int n)
{
	L = (LNode *)malloc(sizeof(LNode));
	if (L == NULL){
		printf("Failed in applying for space!");
		exit(0);
	}
	L -> next = NULL;
	
	LinkedList tail = L;
	int i;
	LNode *p;
	for (i = 0;i < n;i++){
		p = (LNode *)malloc(sizeof(LNode));
		if (L == NULL){
			printf("Failed in applying for space!");
			exit(0);
		}
		
		p -> data = a[i];
		p -> next = NULL;
		tail -> next = p;
		tail = p;
	}
	return L;
}

LinkedList LinkedListMerge(LinkedList La,LinkedList Lb,LinkedList Lc)
{
	LinkedList pa,pb,pc;
	pa = La -> next;
	pb = Lb -> next;
	Lc = La;
	pc = Lc;
	
	while ((pa != NULL) && (pb != NULL)){
		if (pa -> data <= pb -> data){
			pc -> next = pa;
			pc = pa;
			pa = pa -> next;
		}else{
			pc -> next = pb;
			pc = pb;
			pb = pb -> next;
		}
	}
	if (pa != NULL){
		pc -> next= pa;
	}else{
		pc -> next= pb;
	}
	
	free(pb);
	return Lc;
}





int main(void){
	LinkedList list0 = NULL;
	LinkedList list1 = NULL;
	int a[10],b[10],i;
	for (i = 0;i < 10;i++){
		a[i] = 2 * i;
		b[i] = 2 * i + 1;
	}
	
	// Initialize and create a list
	list0 = LinkedListInit(list0);
	list0 = LinkedListCreate(list0,a,10);
	

	// Length of list
	printf("The length of this list is %d.\n",LinkedListLength(list0));
	

	// Get an element from the list
	LinkedList c;
	c = LinkedListGet(list0,10);
	

	// Locate an element
	LNode *d;
	d = LinkedListLocate(list0,8);
	

	// Insert an element
	LinkedListInsert(list0,c,36);
	

	// Delete an element
	LinkedListDel(list0,8,LinkedListLocate(list0,8));


	// print the result after inserting and deleting
	printf("The results after inserting 36 at the last place and deleting 8 :\n");
	int s,t = LinkedListLength(list0);
	LinkedList pre0;
	pre0 = list0 -> next;
	for (s = 0;s < t;s++){
		printf("%d  ",pre0 -> data);
		pre0 = pre0 -> next;
	}
	printf("\n");
	

	//Merge two lists
	list1 = LinkedListInit(list1);
	list1 = LinkedListCreate(list1,b,10);
	LinkedList list2 = NULL;
	list2 = LinkedListInit(list2);
	list2 = LinkedListMerge(list0,list1,list2);
	

	//print results after merging
	int x = LinkedListLength(list2),y;
	LinkedList pre1;
	pre1 = list2 -> next;
	printf("The result after merging:\n");
	for (y = 0;y < x;y++){
		printf("%d   ",pre1  -> data);
		pre1 = pre1 -> next;
	}
	printf("\n");
	system("pause");
}