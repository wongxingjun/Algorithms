class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        vector<string> res;
        string cs;
        int n=s.size();
        if(n<10)
            return res;
        for(int i=0;i<n-9;i++)
        {
            cs.assign(s,i,10);
            if(mp.find(cs)==mp.end())
                mp[cs]=1;
            else
            {
                if(mp[cs]==1)
                {
                    res.push_back(cs);
                    mp[cs]++;
                }
                else continue;
            }
        }
        return res;
    }
};