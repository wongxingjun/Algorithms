#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int main()
{
	int n;
	printf("How many numbers?\n");
	scanf("%d",&n);
	int* a=(int*)malloc(sizeof(int)*n);
	printf("Input %d numbers\n",n);
	int i,j,max,temp;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		max=i;
		for(j=i;j<n;j++)
		{
			if(a[max]<a[j])
					max=j;
		}
		temp=a[i];
		a[i]=a[max];
		a[max]=temp;
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}
