#include <stdio.h>
#include <stdlib.h>

int Eculid(int m,int n)
{
    int r;
    if(m>n)
        r=m%n;
    else
    {
        m=m+n;
        n=m-n;
        m=m-n;
        r=m%n;
    }
    while(r!=0)
    {
        m=n;
        n=r;
        r=m%n;
    }
    return n;
}
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    printf("%d\n",Eculid(m,n));
    return 0;
}
