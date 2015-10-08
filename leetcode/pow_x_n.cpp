class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1;
        else if(n==1)
            return x;
        else if(n<0)
        {
            if(n>INT_MIN)
                return 1/pow(x,-n);
            else
                return 1/(pow(x,-(n+1))*x);
        }
        double tmp=pow(x,n/2);
        return tmp*tmp*pow(x,n-n/2-n/2);
    }
};