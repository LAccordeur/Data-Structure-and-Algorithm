#include<stdio.h>
#define MAXSIZE 40
#define TRUE 1
#define FLASE 0
typedef int bool;

struct node
{
	int data[MAXSIZE];
	int length;
};
typedef struct node SeqList;



void SeqListInit(SeqList L)    //initialize
{
	L.length = 0;
}

int SeqListLength(SeqList L)   //return length
{
	 return L.length;
}

int SeqListGet(SeqList L,int i)
{
	if ((i >= 1) && (i <= L.length)){
		return L.data[i-1];
	}else{
		printf("The value of i is illegal!");
		exit(0);
	}
}

int SeqListLocate(SeqList L,int e)
{
	int i = 1;
	while ((i <= L.length) && (e != L.data[i-1])){
		i++;
	}
	if (i <= L.length){
		return i;
	}else{
		printf("This element isn't in this list!");
		exit(0);
	}
}

int SeqListPrior(SeqList L,int e)
{
	int i;
	i = SeqListLocate(L,e);
	if (i == 1){
		printf("The first element doesn't have a prior element!");
		exit(0);
	}else{
		return L.data[i-2];
	}
}

int SeqListNext(SeqList L,int e)
{
	int i;
	i = SeqListLocate(L,e);
	if (L.length == i){
		printf("The last element doesn't have a next element!");
		exit(0);
	}else{
		return L.data[i];
	}
}

void SeqListInsert(SeqList *L,int i,int b)
{
	if ((*L).length == MAXSIZE){
		printf("There is no extra space to insert an element!");
		exit(0);
	}
	if ((i < 1) || (i > (*L).length)){
		printf("I is illegal!");
		exit(0);
	}
	
	int j;
	for (j = (*L).length-1;j >= i-1;j--){
		(*L).data[j+1] = (*L).data[j];
	}
	(*L).data[i-1] = b;
	(*L).length++;
}

void SeqListDel(SeqList *L,int i)
{
	if ((i < 1) || (i > (*L).length+1)){
		printf("i is illegal!");
		exit(0);
	}
	int j;
	for (j = i;j <= (*L).length-1;j++){
		(*L).data[j-1] = (*L).data[j];
	}
	(*L).length--;
}

bool SeqListEmpty(SeqList L)
{
	return !L.length;
}

void SeqListTraverse(SeqList L)
{
	int i;
	if (SeqListEmpty(L)){
		printf("This is an empty list!");
		exit(0);
	}else{
		for(i = 1;i <= L.length;i++){
			printf("%d  ",L.data[i-1]);
		}
	}
	
}

SeqList list;
int main(void){
	//SeqList list;
	SeqListInit(list);
	
	int i;
	for (i = 0;i < 20;i++){
		list.data[i] = i;
		list.length++;
	}
	
	int a;
	a = SeqListLength(list);
	printf("The length of list is %d.\n",a);
	
	int b;
	b = SeqListGet(list,5);
	printf("The value of 5th element is %d.\n",b);
	
	int c;
	c = SeqListLocate(list,4);
	printf("The location of element 4 is in %dth place\n",c);
	
	int d;
	d = SeqListPrior(list,7);
	printf("The prior element of 7 is %d.\n",d);
	
	int e;
	e = SeqListNext(list,6);
	printf("The next element of 6 is %d.\n",e);
	
	SeqListInsert((&list),9,9);
	int m;
	for (m = 0;m < list.length;m++){
		printf("%d  ",list.data[m]);
	}
	printf("\n");
	
	SeqListDel((&list),1);
	for (i = 0;i < list.length;i++){
		printf("%d  ",list.data[i]);
	}
	printf("\n");
	
	bool f;
	f = SeqListEmpty(list);
	if (f){
		printf("The list is empty\n");
	}else{
		printf("The list isn't empty\n");
	}
	
	SeqListTraverse(list);
	printf("\n");
}