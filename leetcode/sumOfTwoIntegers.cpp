class Solution {
public:
    int getSum(int a, int b) {
        int res;
        while(b)
        {
            res = a^b;
            b = ((a&b) << 1);
            a = res;
        }
        return a;
    }
};