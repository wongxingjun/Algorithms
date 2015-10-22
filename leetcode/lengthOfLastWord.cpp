class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int res=0;
        while(s[n-1]==' ')
            n--;
        int i;
        for(i=n-1;i>=0&&s[i]!=' ';i--)
                res++;
        return res;
    }
};