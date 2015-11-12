class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        int count=0;
        int i=2;
        for(;i<n;i++)
            if(prime(i))
                count++;
        return count;
    }
    
    int prime(int n)
    {
        int i,m;
        if(n%2==0)
            return (n==2);
        if(n%3==0)
            return (n==3);
        if(n%5==0)
            return (n==5);
        m=sqrt(n);
        for(i=7;i<=m;i=i+2)
            if(n%i==0)
                return 0;
        return 1;
    }
};