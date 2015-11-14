class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> f(s.size(),0);
        int i=s.size()-1;
        for(;i>=0;i--)
            f[i]=s[i]-t[i];
        unordered_map<char,int> mp;
        bool flags=true,flagt=true;
        flags=compare(mp, f, s);
        mp.erase(mp.begin(),mp.end());
        flagt=compare(mp, f, t);
        return flags&&flagt;
    }
    
    bool compare(unordered_map<char,int> mp, vector<int> f, string str)
    {
        int i;
        for(i=0;i<str.size();i++)
        {
            if(mp.find(str[i])!=mp.end())
            {
                if(mp[str[i]]!=f[i])
                    return false;
            }
            else mp[str[i]]=f[i];
        }
        return true;
    }
};