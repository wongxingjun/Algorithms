class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string s;
        int n=nums.size();
        if(n==0)
            return res;
        s+=to_string(nums[0]);
        int i=1;
        int cnt=1;
        for(;i<n;i++)
        {
            if(nums[i-1]+1==nums[i])
            {   
                cnt++;
                continue;
            }
            else if(cnt>1)
                s+="->"+to_string(nums[i-1]);
            res.push_back(s);
            s=to_string(nums[i]);
            cnt=1;
        }
        if(cnt>1)
            s+="->"+to_string(nums[n-1]);
        res.push_back(s);
        return res;
    }
};