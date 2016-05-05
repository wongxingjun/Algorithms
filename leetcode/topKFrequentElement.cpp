class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i:nums)
            mp[i]++;
        vector<int> res;
        priority_queue<pair<int,int>> pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push(make_pair(it->second,it->first));
            if(pq.size()>mp.size()-k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
};