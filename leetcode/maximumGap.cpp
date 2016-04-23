class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return 0;
        sort(nums.begin(),nums.end());
        int res=nums[1]-nums[0];
        for(int i=1;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]>res)
                res=nums[i+1]-nums[i];
            else continue;
        }
        return res;
    }
};