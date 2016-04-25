class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int i=0,j=1;
        int cnt=0,stop=0;
        string res="";
        if(strs.size()==0)
            return res;
        for(int i=0; i<strs[0].size(); i++)
        {
            char c=strs[0][i];
            for(j=1; j<strs.size(); j++)
            {
                if(strs[j][i]!=c)
                {
                    stop=1;
                    break;
                }
                else
                    continue;
            }
            if(j==strs.size())
                cnt++;
            if(stop)
                break;
        }
        if(cnt!=0)
            res.assign(strs[0],0,cnt);
        return res;
    }
};
