#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
using namespace std;

double func(double r, vector<int> M)
{
    int n=M.size();
    double sum=0-(double)M[0]*pow(1+r,n-1);
    for(int i=1;i<n;i++)
        sum+=M[i]*pow(1+r,n-i-1);
    return sum;
}

double dfunc(double r, vector<int> M)
{
    int n=M.size();
    double sum=0-(n-1)*M[0]*pow(1+r,n-2);
    for(int i=1;i<n;i++)
        sum+=(n-i-1)*M[i]*pow(1+r,n-i-2);
    return sum;
}

int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int m;
        cin>>m;
        vector<int> M;
        for(int j=0;j<m+1;j++)
        {
            int tmp;
            cin>>tmp;
            M.push_back(tmp);
        }
        double r,tmp;
        r=0.5;
        tmp=0.5;
        r=r-func(r,M)/dfunc(r,M);
        while(fabs(tmp-r)>1e-12)
        {
            tmp=r;
            r=r-func(r,M)/dfunc(r,M);
        }
        printf("Case #%d: %.12f\n",i+1,r);
    }
    return 0;
}
