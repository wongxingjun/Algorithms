class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
            return false;
        vector<int> is(n,1);
        int maxL=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    is[i]=max(is[i],is[j]+1);
                }
            }
            maxL=max(maxL,is[i]);
            if(maxL>=3)
                return true;
        }
        return false;
    }
};