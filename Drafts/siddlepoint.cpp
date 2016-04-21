#include <stdio.h>
void FindSiddlepoint(int **a,int row,int col);
int main(void)
{
	int array[3][5] = {{1,2,3,4,5},{0,0,0,0,0},{0,1,2,3,4}};
	FindSiddlepoint((int**)array,3,5);
	return 0;
//	printf("Enter the values of 5*5 array:\n");
//	int i;
//	for (i = 0;i < 25;i++){
//		scanf(" %d",&a[]);
//	}
}

void FindSiddlepoint(int **a,int row,int col)
{
	int i,j,k,m,n,point;

	for (i = 0;i < row;i++){
		point = a[i][0];
		for (j = 1;j < col;j++){
			if ((*(int *)a + j) <= point){
				point = a[i][j];
				m = i;
				n = j;
			}
			int max = point;
			for (k = 0;k < row;k++){
				if (a[j][k] > point){
					max = a[j][k];
				}
			}
			if (point == max){
				printf("The Siddle Point is located in [%d][%d] and its value is %d",m,n,point);
			}
		}
	}
}