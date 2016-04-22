#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HufmTree
{
	int weight;
	int parent;
	int lchild;
	int rchild;
} HufmTree;

typedef struct CodeNode
{
	char ch;
	char bits[5];
} CodeNode;

void start(char str[],int freq[],HufmTree tree[],CodeNode node[]);
bool CheckFileNull(void);
void ReadFile(char str[]);
void FreqCount(char str[],int freq[]);
void CharSetHuffmanEncoding(HufmTree tree[],CodeNode node[],int freq[],int len);
void CharSetHuffmanDecoding(HufmTree tree[],char *cd,int len);
void StringOut(char str[]);
void ReadString(char *cd);
void Select(HufmTree tree[],int len,int* pos1,int* pos2);
void CreateHuffman(HufmTree tree[],int n);
int InitHuffman(HufmTree tree[],int freq[],int n);
void PrintCode(char str[],CodeNode node[],int len);

int main(void)
{
	int freq[60];			//record the frequency of character
	char str[60];			//record the string from the file
	HufmTree tree[60*2];	//record the HuffmanTree
	CodeNode node[60];		//record the encoding code
//	int n;					//record the length of array of HuffmanTree
	start(str,freq,tree,node);
	return 0;
}


void start(char str[],int freq[],HufmTree tree[],CodeNode node[])
{
	//welcome page
	printf("This is a simple HuffmanTree test.\n");
	printf("Please enter 1 to start after you have created 'String.txt' in the root of E\n");
	printf("Enter 2 to decode.\n\n");

	//select page
	int choice;
	bool mark = false;				//a mark of choice

	do {
		printf("Please enter your choice:");
		scanf("%d",&choice);
		int len;
		if (choice == 1){

			mark = true;
			ReadFile(str);								//read string from file
			StringOut(str);								//Print the original code
			FreqCount(str,freq);						//count the frequency
			len = InitHuffman(tree,freq,60);			//record the length of frequency nodes
			CreateHuffman(tree,len);					//create Huffman tree
			CharSetHuffmanEncoding(tree,node,freq,len); //Encode
			PrintCode(str,node,strlen(str));			//print the huffman code

		} else if (choice == 2) {

			if (mark == true) {
				char cd[300];
				printf("Enter the binary code just printed to decode them:\n");
				scanf("%s",cd);
//				ReadString(cd);
				CharSetHuffmanDecoding(tree,cd,len);
//				StringOut(cd);
				printf("\n");
			} else {
				printf("Please Enter 1 to start at first!");
			}

		} else {

			printf("Invailed value and you have exited!!");

		}
	}  while (choice == 1 || choice == 2);

}

bool CheckFileNull(void)
{
	FILE *fp;
	fp = fopen("F:\\String.txt","r");

	if (!fp) {
		printf("The file doesn't exsit in the root of E!\n");
		fclose(fp);
	} else {
		char temp;
		int res = fscanf(fp,"%c",&temp);
		fclose(fp);
		if (res >= 0 && res <= 127 ){
			return true;
		} else {
			return false;
		}
	}
}


void ReadFile(char str[])
{
	bool res = CheckFileNull();
	int i = 0;
	FILE *fp = fopen("F:\\String.txt","r");

	if (res) {
		while(!feof(fp)){
			fscanf(fp,"%c",&str[i]);
			i++;
		}
		str[i-1] = '\0';
	}
	fclose(fp);
}


void FreqCount(char str[],int freq[])
{
	//count the frequency of characters and 'space' whit a~z = 0~25 and A~Z = 26 ~51 and space = 52
	int i = 0,j = 0;
	for (;j < 60;j++) {
		freq[j] = 0;
	}

	for (;i < strlen(str);i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			j = str[i] - 97;
			freq[j]++;
		} else if (str[i] >= 65 && str[i] <= 90) {
			j = str[i] - 39;
			freq[j]++;
		} else if (str[i] == ' ') {
			j = 52;
			freq[j]++;
		}
	}

}


void CharSetHuffmanEncoding(HufmTree tree[],CodeNode node[],int freq[],int len)
{
	int c,p,i,j = 0;
	int start;
	char cd[7];
	cd[6] = '\0';

	for (i = 0;i < len;i++) {
		printf("\n");
		printf("%d",tree[i].weight);
		printf(":");

		start = 6;
		c = i;

		while ((p = tree[c].parent) != -1) {

			if (tree[p].lchild == c) {
				cd[--start] = '0';
			} else {
				cd[--start] = '1';
			}
			c = p;
		}

		printf("%s",&cd[start]);
		strcpy(node[j].bits,&cd[start]);
		if (tree[i].rchild >= 0 && tree[i].rchild <= 25) {
			node[j].ch = (char)(tree[i].rchild + 97);
		} else if (tree[i].rchild >= 26 && tree[i].rchild <= 51) {
			node[j].ch = (char)(tree[i].rchild + 39);
		} else if (tree[i].rchild == 52){
			node[j].ch = ' ';
		}
		printf("  %c",node[j].ch);
		j++;
	}
	printf("\n");
}


void PrintCode(char str[],CodeNode node[],int len)
{
	printf("The Huffman code is ");
	int i = 0;
	while (str[i] != '\0') {
		int j;
		for (j = 0;j < len;j++) {
			if (str[i] == node[j].ch) {
				printf("%s",node[j].bits);
			}
		}
		i++;
	}
	printf("\n");
}


void CharSetHuffmanDecoding(HufmTree tree[],char *cd,int len)
{
	int p = 2 * len -2;
	int i = 0;

	printf("The decoding result is ");
	while (cd[i] != '\0') {

		while ((tree[p].lchild) != 0 && cd[i] != '\0') {
			if (cd[i] == '0') {
				p = tree[p].lchild;
			} else {
				p = tree[p].rchild;
			}
			i++;
		}

		if (tree[p].lchild == 0) {
			if (tree[i].rchild >= 0 && tree[i].rchild <= 25) {
				printf("%c",(char)(tree[i].rchild + 97));
			} else if (tree[i].rchild >= 26 && tree[i].rchild <= 51) {
				printf("%c",(char)(tree[i].rchild + 39));
			} else if (tree[i].rchild == 52){
				printf("%c",' ');
			}
			p = 2 * len - 1;
		} else {
			printf("Error in decoding");
			break;
		}
	}
}


void StringOut(char str[])
{
	int i = 0;
	char ch = str[i];
	while (ch != '\0') {
		printf("%c",str[i]);
		i++;
		ch = str[i];
	}
}


void ReadString(char* cd)
{
	char ch;
	int i;
	for (i = 0;(ch = getchar()) != '\n';i++) {
		cd[i] = ch;
		ch = getchar(); 
	}
	cd[i] = '\0';
}


void Select(HufmTree tree[],int len,int* pos1,int* pos2)
{
	int min = 255;
	int i,j;
	*pos1 = 0;
	*pos2 = 0;

	for (i = 0;i < len;i++) {

		if (tree[i].parent == -1) {
			if (tree[i].weight < min) {
				min = tree[i].weight;
				*pos1 = i;
			}
		}

	}
	min = 255;

	for (j = 0;j < len;j++) {

		if (j == *pos1) {
			continue;
		}

		if (tree[j].parent == -1) {
			if (tree[j].weight < min) {
				min = tree[j].weight;
				*pos2 = j;
			}
		}
	}

}


void CreateHuffman(HufmTree tree[],int n)
{
	int m = 2 * n;						//Length of Huffman tree
	int i;

	for (i = n;i < m - 1;i++) {
		int pos1,pos2;
		HufmTree node;					//record the new huffman tree node

		Select(tree,i,&pos1,&pos2);
		node.weight = tree[pos1].weight + tree[pos2].weight;
		tree[pos1].parent = i;			//mark the node had visited and record their parent
		tree[pos2].parent = i;
		node.lchild = pos1;
		node.rchild = pos2;
		node.parent = -1;

		tree[i] = node;
	}			
}


int InitHuffman(HufmTree tree[],int freq[],int n)
{
	int i,j;
	for (i = 0,j = 0;i < n;i++) {

		if (freq[i] != 0) {
			tree[j].weight = freq[i];
			tree[j].parent = -1;
			tree[j].rchild = i;				//record the character
			tree[j].lchild = 0;
			j++;
		}

	}

	return j;
}