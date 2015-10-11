#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void selectKitems(int arr[],int n,int k)
{
	int i=0;
	int* reservoir=(int*)malloc(sizeof(int)*k);
	for(;i<k;i++)
		reservoir[i]=arr[i];
	srand(time(NULL));
	for(;i<n;i++)
	{
		int j=rand()%(i+1);
		if(j<k)
			reservoir[j]=arr[i];
	}
	for(i=0;i<k;i++)
		printf("%d\n",reservoir[i]);
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int n=15;
	int k=6;
	selectKitems(arr,n,k);
	return 0;
}
