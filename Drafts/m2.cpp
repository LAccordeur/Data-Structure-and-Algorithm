// 寻找可表示为两组整数的立方和的整数 

#include<stdio.h>
#include<math.h> 
void func(long n);
void quickSort(int num[],int lower,int upper);
int partition(int num[],int left,int right);
void display(int num[],int count);

int main(void){
	long max;
	printf("Enter the upper bound:");
	scanf("%d",&max);
	func(max);
	return 0;
}

void func(long n)
{
	int i,j,N,count;
	int sum[500000];
	N = (int)pow(n,1.0/3);
	count = 0;
	
	for (i = 1;i <= N;i++){
		for (j = i;j <= N && i*i*i + j*j*j < n;j++){
			sum[count] = i*i*i + j*j*j;
			count++;
		}
	}
	quickSort(sum,0,count-1);
	
	for (i = 0;i < count - 1;i++){
		if (sum[i] == sum[i+1]){
			printf("%d\n",sum[i]);
		}
	}
	
//	display(sum,count-1);
}

void quickSort(int num[],int lower,int upper)  
{  
    int partition(int [],int ,int);  
    int pivot;  
    //递归调用   
    pivot=partition(num,lower,upper);  
    if(lower < pivot)  
        quickSort(num,lower,pivot-1);  
    if(pivot < upper)  
        quickSort(num,pivot+1,upper);  
  
}  
  
int partition(int num[],int left,int right)  
{  
     int pivot,temp;  
       
     pivot = num[left];  
     while(left<right)  
     {  
        //从右往左扫描   
        while(num[right]>=pivot && left<right)  
            right--;  
        if(right!=left)  
        {  
            num[left]=num[right];  
            left++ ;  
        }  
          
        //从左往右扫描   
        while(num[left]<=pivot && left<right)  
            left++;  
        if(right!=left)  
        {  
            num[right]=num[left];  
            right--;  
        }  
     }  
     num[left]=pivot;  
     return(left);  
}  

void display(int num[],int count)  
{  
    int i;  
    for(i=0;i<count;i++)  
    {  
         printf("%d\n",num[i]);  
    }  
    printf("\n");  
}  
