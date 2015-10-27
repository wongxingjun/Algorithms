class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int mid=n/2;
        int i=0;
        int l=1,r=n-1;
        int count=0;
        while(l<r)
        {
            count=0;
            mid=l+(r-l)/2;
            for(i=0;i<n;i++)
                if(nums[i]<=mid)
                    count++;
            if(count<=mid)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};