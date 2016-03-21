// Chapter1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int factor(int n);
float sum(int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	float s=0;

	printf("Enter the n :");
	scanf("%d",&n);

	s = sum(n);

	printf("The answer is %f.",s);
	return 0;
}

int factor(int n)
{
	if (n == 1){
		return 1;
	}else{
		return n * factor(n-1);
	}
}

float sum(int n)
{
	float s = 0;
	int i = 1;

	for(;i <= n;i++){
		s = s + 1.0/factor(i);
	}

	return s;
}
