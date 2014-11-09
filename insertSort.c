/*
Author: wangxingjun
Time: 2014-11-2
*/
#include<stdio.h>
#include<malloc.h>
int main()
{
	int n;
	printf("How many numbers?\n");
	scanf("%d",&n);
	int* a=(int*)malloc(sizeof(int)*n);
	int i,j;
	scanf("Input the numbers:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0&&a[j]>temp)
		{
		    a[j+1]=a[j];
		    j--;
		}
		if(j!=i-1)
			a[j+1]=temp;
	}
	for(i=0;i<n;i++)
		printf("%d\n",a[i]);
	free(a);
	return 0;
}
