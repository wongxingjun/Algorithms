//https://en.wikipedia.org/wiki/Catalan_number
class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        else
            return (long)(4*n-2)*numTrees(n-1)/(n+1);
    }
};