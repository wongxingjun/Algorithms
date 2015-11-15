class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res=0;
        if(divisor==0||(dividend==INT_MIN&&divisor==-1))
            return INT_MAX;
        int flag=(dividend>=0?1:-1)*(divisor>=0?1:-1);
        long long a=abs((long long)dividend);
        long long b=abs((long long)divisor);
        while(a>=b)
        {
            long long tmp=b;
            int mul=1;
            while(a>=(tmp<<1))
            {
                tmp=tmp<<1;
                mul=mul<<1;
            }
            a-=tmp;
            res+=mul;
        }
        return res*flag;
    }
};