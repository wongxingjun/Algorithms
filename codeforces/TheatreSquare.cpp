#include <iostream>

using namespace std;

int main()
{
    long long n1,n2;
    int n,m,a;
    cin>>n>>m>>a;
    n1=n/a;
    if(n%a)
        n1++;
    n2=m/a;
    if(m%a)
        n2++;
    n1*=n2;
    cout<<n1<<endl;
    return 0;
}

