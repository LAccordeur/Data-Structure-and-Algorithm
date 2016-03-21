#include<stdio.h>
double sum(int n);

int main(void){
	int n;
	double s;
	
	printf("Enter the n :");
	scanf("%d",&n);
	
	s = sum(n);
	
	printf("%.9f",s);
	
	return 0;
}

double sum(int n)
{
	int i = 1,j = 1;
	double s = 0;
	
	for (;i <= n;i++){
		s = s + 1.0 / j;
		j = j * (i + 1);
	}
	
	return s;
}