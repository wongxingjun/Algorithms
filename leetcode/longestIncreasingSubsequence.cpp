class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return n;
        vector<int> lis(n,1);
        int maxL=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
            maxL=max(maxL,lis[i]);
        }
        return maxL;
    }
};