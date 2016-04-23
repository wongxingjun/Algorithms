class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> mp;
        istringstream in(str);
        int i=0,n=pattern.size();
        string w;
        char c;
        for(;in>>w;i++)
        {
            c=pattern[i];
            if(mp.find(c)==mp.end())
            {
                for(auto it=mp.begin();it!=mp.end();it++)
                {
                    if(it->second==w)
                        return false;
                }
                mp[c]=w;
            }
            else if(mp[c]!=w)
                return false;
        }
        if(i!=pattern.size())
            return false;
        return true;
    }
};