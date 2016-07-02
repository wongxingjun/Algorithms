class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> ch(256,false);
        int res=0,cur=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            int c=(int)s[i];
            if(ch[c])
            {
                int newCur=i;
                while((int)s[newCur-1]!=c)
                    newCur--;
                for(int j=cur;j<newCur;j++)
                    ch[(int)s[j]]=false;
                cur=newCur;
            }
            else
            {
                int len=i-cur+1;
                if(res<len)
                    res=len;
            }
            ch[c]=true;
        }
        return res;
    }
};
