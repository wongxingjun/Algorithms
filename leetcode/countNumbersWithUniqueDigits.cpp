class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int num = 0;
        for(int i = n; i >= 1; --i)
        {
            int part = 9;
            for(int j = 0; j < i - 1; ++j)
            {
                part *= 9 - j;
            }
            num += part; 
        }
        return num + 1;
    }
};