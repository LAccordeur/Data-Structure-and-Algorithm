#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentinfo
{
	char name[10];
	int age;
};
typedef struct studentinfo Studentinfo;

struct node
{
	Studentinfo data;
	struct node *next;
};
typedef struct node ListNode;
typedef struct node *ListPtr;

ListPtr ReadFile(FILE *fp);
bool check_filenull(void);
ListPtr ListCreate(void);
void OutPut(ListPtr L);
void ListInsert(ListPtr L,ListPtr p,char *name,int age);
void ListDelete(ListPtr L,char *name);
void ListFree(ListPtr L);
ListPtr ListLocate(ListPtr L,char *name);
ListPtr ListMerge(ListPtr La,ListPtr Lb);
ListPtr ListReserve(ListPtr L);
void WriteFile(FILE *fp,ListPtr L);
void InfoFlush(ListPtr L);
ListPtr ListCreate1(void);

int main(void)
{
	ListPtr La,Lb = NULL;
	printf("Create a List through reading from a file == 1\n");
	printf("Inserst an element == 2\n");
	printf("Delete an element == 3\n");
	printf("Create another List == 4\n");
	printf("Merge two lists == 5\n");
	printf("Write the information into a file == 6\n");
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
			case 4: Lb = ListCreate1();
					OutPut(Lb);
					break;
			case 5: ListPtr Lc;
					Lc = ListMerge(La,Lb);
					OutPut(Lc);
					break;
			case 6: InfoFlush(Lc);
					break;
			default:break;
		}
	}while(choice != 0);
	ListFree(La);
}

// Read the information from a file and create a list

ListPtr ReadFile(FILE *fp)
{
	ListPtr p;
	p = (ListNode *)malloc(sizeof(ListNode));
	fscanf(fp,"%s",(p -> data).name);
	fscanf(fp,"\t%d\n",&((p -> data).age));
	return p;
}

bool check_filenull()
{
	FILE *fp;
	fp = fopen("F:\\studentinfo.txt","r");
	if (!fp){
		printf("The file doesn't exsit in the root of E!\n");
		fclose(fp);
	}else{
		int temp;
		int res = fscanf(fp,"%d",&temp);
		fclose(fp);
		if (res <= 0){
			return false;
		}else{
			return true;
		}
	}
}

ListPtr ListCreate()
{
	bool res = check_filenull();
	FILE *fp = fopen("F:\\studentinfo.txt","r");

	ListPtr L,pre;
	L = (ListNode *)malloc(sizeof(ListNode));
	pre = L;
	while(!feof(fp)){
		pre -> next = ReadFile(fp);
		pre = pre -> next;
	}
	pre -> next = NULL;

	return L;
}

// some operations

void OutPut(ListPtr L)
{
	ListPtr temp = L -> next;
	if (temp == NULL){
		printf("This list is empty!");
	}else{
		int i = 1;
		while(temp != NULL){
			printf("The %d th student's name is %s\n",i,(temp -> data).name);
			printf("The %d th student's age is %d\n",i,(temp -> data).age);
			i++;
			temp = temp -> next;
		}
	}
}


void ListInsert(ListPtr L,ListPtr p,char *name,int age)
{
	ListPtr temp;
	temp = L ;
	while (temp != NULL && temp -> next != p){
		temp = temp -> next;
	}

	p = (ListNode *)malloc(sizeof(ListNode));
	strcpy((p -> data).name,name);
	(p -> data).age = age;

	p -> next = temp -> next;
	temp -> next = p;
}

void ListDelete(ListPtr L,char *name)
{
	ListPtr temp = L -> next;
	while(temp != NULL && !strcmp(name,(temp -> next -> data).name)){
		temp = temp -> next;
	}

	if (temp == NULL){
		printf("This student isn't in the list!");
	}else{
		ListPtr pre;
		pre = temp -> next;
		temp -> next= pre -> next;
		free(pre);
	}
}

void ListFree(ListPtr L)
{
	ListPtr pre,pre0;
	pre = L;
	while(pre != NULL){
		pre0 = pre -> next;
		free(pre);
		pre = pre0;
	}
}

ListPtr ListLocate(ListPtr L,char *name)
{
	ListPtr temp = L -> next;
	while (temp != NULL && !strcmp(name,(temp -> data).name)){
		temp = temp -> next;
	}
	if (temp == NULL){
		printf("This student isn't in the list!");
	}
	return temp;
}


ListPtr ListMerge(ListPtr La,ListPtr Lb)
{
	ListPtr pa,pb,pc,Lc;
	pa = La -> next;
	pb = Lb -> next;
	Lc = La;
	pc = Lc;

	while (pa != NULL && pb != NULL){
		if ((pa -> data).age <= (pb -> data).age){
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

	ListReserve(Lc);
	free(Lb);
	return Lc;
}

ListPtr ListReserve(ListPtr L)
{
	ListPtr p,q;
	p = L -> next;
	q = p -> next;
	p -> next = NULL;
	while(q != NULL){
		L -> next = q;
		q = q -> next;
		L -> next = p;
		p = p -> next;
	}
	return L;
}

void WriteFile(FILE *fp,ListPtr L)
{
	fprintf(fp,"%s\t",(L -> data).name);
	fprintf(fp,"%d\n",(L -> data).age);
}

void InfoFlush(ListPtr L)
{
	FILE *fp = fopen("F:\\studentinfo.txt","w");
	ListPtr temp = L -> next;
	while(temp != NULL){
		WriteFile(fp,temp);
		temp = temp -> next;
	}
	fclose(fp);
}

ListPtr ListCreate1(void)
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
		scanf(" %s",(p -> data).name);
		printf("Enter the %d th student's age: ",i+1);
		scanf(" %d",&(p -> data).age);

		p -> next = NULL;
		tail -> next = p;
		tail = p;
	}

	return L;
}