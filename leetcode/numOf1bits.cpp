/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t temp=n;
        uint32_t res=0;
        if(n==0)
            return res;
        else
        {
            while(temp!=0)
            {
                if(temp%2==1)
                    res++;
                temp=temp/2;
            }
        }
        return res;
    }
};
