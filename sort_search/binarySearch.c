/*Binary search algorithm*/
#include <stdio.h>
#include <stdlib.h>

int Bsearch(int a[],int left,int right,int key)
{
    int midd=(left+right)/2;
    if(a[midd]==key)
        return midd;
    while(left<right)
    {
        if(key>a[midd])
        {
            left=midd+1;
            return Bsearch(a,left,right,key);
        }
        else
        {
            right=midd-1;
            return Bsearch(a,left,right,key);
        }
    }
    return -1;
}
int main()
{
    int a[10]={0,1,2,3,4,5,6,7,8,9};//a must be a sorted array!!
    int key;
    scanf("%d",&key);
    if(Bsearch(a,0,9,key)>=0)
        printf("element [%d] matches\n",Bsearch(a,0,9,key));
    else
        printf("no element matches!\n");
    return 0;
}
