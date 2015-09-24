class Solution {
public:
    bool isAnagram(string s, string t) {
        int lenS=s.size();
        int lenT=t.size();
        if(lenS!=lenT)
            return false;
        int a[26];
        int i=0;
        while(i<26)
        {
            a[i]=0;
            i++;
        }
        i=0;
        while(i<lenS)
        {
            a[s[i]-'a']+=1;
            a[t[i]-'a']-=1;
            i++;
        }
        i=0;
        while(i<26)
        {
            if(a[i]!=0)
                return false;
            i++;
        }
        return true;
    }
};