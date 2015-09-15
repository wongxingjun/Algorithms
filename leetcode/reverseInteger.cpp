class Solution {
public:
    int reverse(int x) {
        int sig;
        long rx=0;
        if(x>0)
            sig=1;
        else
        {
            sig=-1;
            x=-x;
        }
        while(x>0)
        {
            rx=rx*10+x%10;
            x/=10;
        }
        if(rx>2147483647)
            return 0;
        return rx*sig;
    }
};