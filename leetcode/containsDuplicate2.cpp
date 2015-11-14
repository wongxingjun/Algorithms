class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k<=0)
            return false;
        unordered_map<int,int> mp;
        int i=0;
        for(;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end()&&i-mp[nums[i]]<=k) return true;
            else mp[nums[i]]=i;
        }
        return false;
    }
};