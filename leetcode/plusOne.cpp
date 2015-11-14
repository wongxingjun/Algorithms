class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int n=digits.size();
        if(n==0)
            return digits;
        int cnt=(digits[n-1]+1)/10;
        res.insert(res.begin(),(digits[n-1]+1)%10);
        int i=n-2;
        int tmp;
        for(;i>=0;i--)
        {
            tmp=(cnt+digits[i])/10;
            res.insert(res.begin(),(cnt+digits[i])%10);
            cnt=tmp;
        }
        if(digits[0]+cnt>=10)
            res.insert(res.begin(),cnt);
        return res;
    }
};