class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> pre;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>k)
                pre.erase(nums[i-k-1]);
            auto low=pre.lower_bound(nums[i]-t);
            if(low!=pre.end()&&abs(nums[i]-*low)<=t)
                return true;
            pre.insert(nums[i]);
        }
        return false;
    }
};