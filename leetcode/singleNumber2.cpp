class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int i;
        unordered_map<int,int> mp;
        for(i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=1;
            else
                mp[nums[i]]++;
        }
        auto it=mp.begin();
        while(it!=mp.end())
        {
            if(it->second==1)
                return it->first;
            it++;
        }
    }
};