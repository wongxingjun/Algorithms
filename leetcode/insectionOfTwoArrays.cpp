class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int,int> mp1,mp2;
        for(auto i:nums1)
            mp1[i]++;
        for(auto j:nums2)
            mp2[j]++;
        for(auto it=mp1.begin();it!=mp1.end();it++)
        {
            if(mp2.find(it->first)!=mp2.end())
                res.push_back(it->first);
        }
        return res;
    }
};