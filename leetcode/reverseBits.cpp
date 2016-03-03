class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result=0;
        uint32_t i=0;
        for(int i=1;i!=0;i<<=1)
        {
            result<<=1;
            if(n&1)
                result|=1;
            n>>=1;
        }
        return result;
    }
};