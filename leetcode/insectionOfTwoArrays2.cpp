class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> mp1,mp2,resmp;
        for(auto i:nums1)
            mp1[i]++;
        for(auto j:nums2)
            mp2[j]++;
        for(auto it=mp1.begin();it!=mp1.end();it++)
        {
            if(mp2.find(it->first)!=mp2.end())
                resmp[it->first]=min(it->second,mp2.find(it->first)->second);
        }
        for(auto it=resmp.begin();it!=resmp.end();it++)
        {
            for(int i=0;i<it->second;i++)
                res.push_back(it->first);
        }
        return res;
    }
};