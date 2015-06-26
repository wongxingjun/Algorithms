#include <stdio.h>
#include <stdlib.h>
int Partion(int* L,int low,int high)
{
    int pivotkey=L[low];
    int temp;
    while(low<high)
    {
        while(low<high&&L[high]>=pivotkey)
            --high;
        temp=L[low];
        L[low]=L[high];
        L[high]=temp;
        while(low<high&&L[low]<=pivotkey)
            ++low;
        temp=L[low];
        L[low]=L[high];
        L[high]=temp;
    }
    return low;
}
 
void QSort(int* L,int low,int high)
{
    int pivotloc;
    if(low<high)
    {
        pivotloc=Partion(L,low,high);
        QSort(L,low,pivotloc-1);
        QSort(L,pivotloc+1,high);
    }
}
int main()
{
    int a[10]= {6,7,8,0,1,2,9,4,3,5};
    QSort(a,0,9);
    int i;
    for(i=0; i<10; i++)
        printf("%d ",a[i]);
    return 0;
}