class Solution
{
public:
    string getHint(string secret, string guess)
    {
        map<char,int> mps;
        map<char,int> mpg;
        string res="";
        int A=0,B=0;
        int n=secret.size();
        for(int i=0; i<n; i++)
        {
            char s=secret[i],g=guess[i];
            if(s==g)
                A++;
            else
            {
                if(mps.find(s)==mps.end())
                    mps[s]=1;
                else mps[s]++;
                if(mpg.find(g)==mpg.end())
                    mpg[g]=1;
                else mpg[g]++;
            }
        }
        res+=to_string(A);
        res.insert(res.end(),'A');
        for(auto i=mps.begin(); i!=mps.end(); i++)
        {
            if(mpg.find(i->first)==mpg.end())
                continue;
            else B+=min(i->second,mpg[i->first]);
        }
        res+=to_string(B);
        res.insert(res.end(),'B');
        return res;
    }
};
