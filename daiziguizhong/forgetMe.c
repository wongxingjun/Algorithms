/*
   给定一个整型数组a[1,2,3,...,n],设计一种算法生成一个数组b[1,2,3,...,n]
   使得b[i]=a[1]*a[2]*a[3}*...*a[n]/a[i],要求不能使用除法，时间复杂度O(n)
   空间复杂度O(1)
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{
	int n,i,temp;
	scanf("%d",&n);
	if(n<=0)
		return 0;
	int* a=(int*)malloc(sizeof(int)*n);
	int* b=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	b[0]=1;
	b[1]=a[0];
	for(i=2;i<n;i++)
		b[i]=b[i-1]*a[i-1];
	temp=1;
	for(i=n-2;i>=0;i--)
	{
		temp=temp*a[i+1];
		b[i]=temp*b[i];
	}
	for(i=0;i<n;i++)
		printf("%d ",b[i]);
	return 0;
}
