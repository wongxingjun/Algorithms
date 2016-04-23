class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1,len2;
        len1=haystack.size();
        len2=needle.size();
        if(len1<len2) return -1;
        else if(len1==len2&&len1==0) return 0;
        int e=len1-len2;
        int i,j;
        for(i=0;i<=e;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(haystack[i+j]!=needle[j])
                    break;
            }
            if(j==len2)
                return i;
        }
        return -1;
    }
};