#include<stdio.h>

int main(void){
	int list[20],a1,d,s1 = 300,s2 = 330,s = 630,i;
	
	d = (s2 - s1) / 10;
	a1 = (s - (190 * d)) / 20;
	
	for (i = 0;i < 20;i++){
		list[i] = a1 + i * d;
		printf("%d   ",list[i]);
	}
	printf("\n");
	return 0;
}