class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int tmp=0;
        int y=x;
        while(y)
        {
            tmp+=y%10;
            if(y>=10)
                tmp*=10;
            y/=10;
        }
        return x==tmp;
    }
};