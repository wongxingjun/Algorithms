class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]]=1;
            else
            {
                if(mp[nums[i]]==2)
                    continue;
                else
                    mp[nums[i]]++;
            }
        }
        nums.erase(nums.begin(),nums.end());
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==1)
                nums.push_back(it->first);
            else
            {
                nums.push_back(it->first);
                nums.push_back(it->first);
            }
        }
        return nums.size();
    }
};