#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int merge2(int a[],int an,int b[],int bn,int res[])//merge two sorted arrays,a simple demo.
{
    int i,j,k;
    i=j=k=0;
    while(i<an&&j<bn)
    {
        if(a[i]<b[j])
        {
            res[k]=a[i];
            i++;
            k++;
        }
        else
        {
            res[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<an)
    {
        res[k]=a[i];
        k++;
        i++;
    }
    while(j<bn)
    {
        res[k]=b[j];
        k++;
        j++;
    }
    return 0;
}

int merge(int a[],int start,int mid,int end)//merge two sorted sub-arrays in an array.
{
    int *temp=(int*)malloc(sizeof(int)*(end-start+1));
    int i=start,j=mid+1;
    int k=0;
    while(i<=mid&&j<=end)
    {
        if(a[i]<a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        k++;
        i++;
    }
    while(j<=end)
    {
        temp[k]=a[j];
        k++;
        j++;
    }
    for(i=0;i<k;i++)
        a[start+i]=temp[i];
    return 0;
}

int mergeSort(int a[],int start,int end)//merge sort
{
    if(start<end)
    {
        int mid=(start+end)>>1;
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);
        merge(a,start,mid,end);
    }
    return 0;
}

int main()
{
    int a[10]= {-5,-3,-2,-1,1,5,6,7,9,10};
    int b[8]= {-6,-4,0,2,3,4,9,11};
    int c[11]={1,-2,3,-1,0,9,3,5,10,12,-9};
    int *res=(int*)malloc(sizeof(int)*18);
    merge2(a,10,b,8,res);
    int i;
    for(i=0; i<18; i++)
        printf("%d ",res[i]);
    printf("\n");
    mergeSort(c,0,10);
    for(i=0;i<11;i++)
        printf("%d ",c[i]);
    free(res);
    return 0;
}
