/*给定一个数组a[0,1,2,...,n-1],其中只有正数和负数,现在要设计
算法把正数全部放在数组前面，负数全部放在后面，分隔正数和负数*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int main()
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(sizeof(int)*n);
    int i,j;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    i=0;
    j=n-1;
    int temp;
    while(i!=j)
    {
        if(a[i]<0&&a[j]>0)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        else if(a[i]>0)
            i++;
        else if(a[j]<0)
            j--;
    }
    for(i=0;i<n;i++)
		printf("%d ",a[i]);
	free(a);
	return 0;
}
