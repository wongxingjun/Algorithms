class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        int i;
        for(i=0;i<nums.size();i++)
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
                res.push_back(it->first);
            it++;
        }
        return res;
    }
};