#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stuinfo
{
	char stuName[10];
	int Age;
}Stuinfo;

typedef struct node
{
	Stuinfo data;
	struct node *next;
}ListNode,*ListPtr;

ListPtr ListCreate(void);
void ListInsert(ListPtr L,ListPtr h,char *x,int age);
void ListDelete(ListPtr L,char *s);
ListPtr ListMerge(ListPtr La,ListPtr Lb);
void OutPut(ListPtr L);
ListPtr ListLocate(ListPtr L,char *name);
ListPtr ListReverse(ListPtr L);

int main(void)
{
	ListPtr La,Lb;
	printf("Create a List == 1\n");
	printf("Inserst an element == 2\n");
	printf("Delete an element == 3\n");
	printf("Create another List == 4\n");
	printf("Merge two lists == 5\n");
	printf("Exit == 0\n\n");

	int choice;


	do{
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1: La = ListCreate();
					OutPut(La);
					break;
			case 2: printf("Which place do you want to insert? and enter the name of that place:");
					char name1[10],name2[10];
					int age;
					scanf(" %s",name1);

					printf("Enter the name you want to insert: ");
					scanf(" %s",name2);
					printf("Enter the age:");
					scanf("%d",&age);
					ListInsert(La,ListLocate(La,name1),name2,age);
					OutPut(La);
					break;
			case 3: printf("Enter the name you want to delete:");
					char name3[10];
					scanf(" %s",name3);
					ListDelete(La,name3);
					OutPut(La);
					break;
			case 4: Lb = ListCreate();
					OutPut(Lb);
					break;

			case 5: ListPtr Lc;
					Lc = ListMerge(La,Lb);
					OutPut(Lc);
					break;
			default:break;
		}
	}while(choice != 0);
}


ListPtr ListCreate(void)
{
	ListPtr L;
	L = (ListNode *)malloc(sizeof(ListNode));
	if (L == NULL){
		printf("Fail to apply the space!");
		exit(0);
	}

	ListPtr tail;  //create a tail pointer
	L -> next = NULL;
	tail = L;

	printf("Enter the length of this list: ");
	int length,i;                            //i is used to count number
	scanf(" %d",&length);

	for(i = 0;i < length;i++){
		ListPtr p;
		p = (ListNode *)malloc(sizeof(ListNode));

		if (p == NULL){
			printf("Fail to apply the space!");
			exit(0);
		}

		printf("Enter the %d th student's name: ",i+1);
		scanf(" %s",(p -> data).stuName);
		printf("Enter the %d th student's age: ",i+1);
		scanf(" %d",&(p -> data).Age);

		p -> next = NULL;
		tail -> next = p;
		tail = p;
	}

	return L;
}


void ListInsert(ListPtr L,ListPtr h,char *name,int age)
{
	ListPtr q,pre;
	q = (ListNode *)malloc(sizeof(ListNode));
	if (q == NULL){
		printf("Fail to apply the space!");
		exit(0);
	}

	strcpy((q -> data).stuName,name);
	(q -> data).Age = age;

	pre = L;            // find prior
	while(pre != NULL && pre -> next != h){
		pre = pre -> next;
	}

	q -> next = pre -> next;
	pre -> next = q;
}

void ListDelete(ListPtr L,char *name)
{
	ListPtr pre,p;
	pre = L;
	while(pre -> next != NULL && (strcmp((pre -> next -> data).stuName,name))){
		pre = pre -> next;
	}
	p = pre -> next;

	if (p != NULL){
		pre -> next = p -> next;
		free(p);
	}
}


ListPtr ListMerge(ListPtr La,ListPtr Lb)
{
	ListPtr Lc,pa,pb,pc;
	pa = La -> next;
	pb = Lb -> next;
	Lc = La;
	pc = Lc;


	while((pa != NULL) && (pb != NULL)){
		if((pa -> data).Age <= (pb -> data).Age){
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
		pc -> next = pa;
	}else{
		pc -> next = pb;
	}

	Lc = ListReverse(Lc);
	return Lc;
	free(Lb);
}

ListPtr ListReverse(ListPtr L)
{
	ListPtr p,q;
	if (L -> next && L -> next -> next){
		p = L -> next;
		q = p -> next;
		p -> next = NULL;

		while(q){
			p = q;
			q = q -> next;
			p -> next = L -> next;
			L -> next = p;
		}
	}
	return L;
}

ListPtr ListLocate(ListPtr L,char *name)
{
	ListPtr p;
	p = L -> next;
	while((p != NULL) && strcmp((p -> data).stuName,name)){
		p = p -> next;
	}
	return p;
}


void OutPut(ListPtr L)
{
	ListPtr p;
	p = L -> next;
	int i = 1;
	while (p != NULL){
		printf("The %d th student's information :%s(name)  %d(age)\n",i,(p -> data).stuName,(p -> data).Age);
		p = p -> next;
		i++;
	}
	printf("\n");
}