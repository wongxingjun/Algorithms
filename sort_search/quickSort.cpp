#include<iostream>
#include<stdio.h>
using namespace std;

void print(int a[], int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}


int partition(int a[], int low, int high)
{
    int p=a[low];
    while(low<high)
    {
        while(low<high&&a[high]>=p)
            high--;
        swap(a[low],a[high]);
        //print(a,10);
        while(low<high&&a[low]<=p)
            low++;
        swap(a[low],a[high]);
        //print(a,10);
    }
    print(a,10);
    return low;
}

void myQsort(int a[], int low, int high)
{
    if(low < high)
    {
        int p = partition(a, low, high);
        myQsort(a, low,p-1);
        myQsort(a, p+1, high);
    }
}

int main()
{
    int a[10]= {6,7,8,0,1,2,9,4,3,5};
    myQsort(a, 0, 9);
    return 0;
}
