// 寻找可表示为两组整数的立方和的整数 

#include<stdio.h>
void func(int n);

int main(void){
	int max;
	printf("Enter the upper bound:");
	scanf("%d",&max);
	func(max);
	return 0;
}

void func(int n)
{
	int i;
	for (i = 0;i <= n;i++){
		int count = 0,m = 1,n = 1;
		for (m = 1;m*m*m <= i;m++){
			for (n = m;m*m*m+n*n*n <= i;n++){
				if (n*n*n + m*m*m == i){
					count++;
				}
			}
		}
		
		if (count >= 2){
			printf("Find it! ");
			for (m = 1;m*m*m <= i;m++){
				for (n = m;m*m*m+n*n*n <= i;n++){
					if (n*n*n + m*m*m == i){
						printf("%d^3 + %d^3 = ",m,n);
					}
				}
			}
			printf("%d\n",i);
		}
	}
}