class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        int i=0;
        while(i<=num)
        {
            res.push_back(hammingWeight(i));
            i++;
        }
        return res;
    }
    
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