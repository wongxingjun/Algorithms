class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<3) return 0;
        int res=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                    return target;
                else if(sum<target)
                    l++;
                else r--;
                if(abs(sum-target)<abs(res-target))
                    res=sum;
            }
        }
        return res;
    }
};