#include <stdio.h>
void FindSiddlePoint(int (*a)[4],int row,int col);

int main(void)
{
	int a[4][4],i,j;
	printf("Enter the values of this 4*4 array:\n");
	for (i = 0;i < 4;i++){
		for (j = 0;j < 4;j++){
			scanf(" %d",&a[i][j]);
		}
	}
	FindSiddlePoint(a,4,4);
	return 0;
}

void FindSiddlePoint(int (*a)[4],int row,int col)
{
	int i,j,k,min,mark,count = 0;
	for (i = 0;i < row;i++){
		min = a[i][0];
		for (j = 1;j < col;j++){
			if (a[i][j] < min){
				min = a[i][j];
			}
		}

		for (j = 0;j < col;j++){
			if (a[i][j] == min){
				for (k = 0,mark = 1;k < col;k++){
					if (a[k][j] > min){
						mark = 0;
					}
				}
				if (mark == 1){
					printf("Find the siddle point!\n");
					printf("It is located in [%d][%d] and its value is %d.\n",i,j,a[i][j]);
					count++;
				}
			}
		}
	}
	if (count == 0){
		printf("This no siddle point in this array.");
	}
}