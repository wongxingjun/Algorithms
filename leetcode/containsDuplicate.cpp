class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return false;
        unordered_map<int,int> mp;
        int i;
        for(i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=1;
            else
                return true;
        }
        return false;
    }
};