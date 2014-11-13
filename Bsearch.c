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
    int a[10]={0,3,6,7,8,1,12,42,72,89};
    int key;
    scanf("%d",&key);
    if(Bsearch(a,0,9,key)>=0)
        printf("element [%d] matches\n",Bsearch(a,0,9,key));
    else
        printf("no element matches!\n");
    return 0;
}
