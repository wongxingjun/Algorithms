class Solution {
public:
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(isVowels(s[i])&&isVowels(s[j]))
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(isVowels(s[i])&&!isVowels(s[j]))
                j--;
            else if(!isVowels(s[i])&&isVowels(s[j]))
                i++;
            else if(!isVowels(s[i])&&!isVowels(s[j]))
            {
                i++;
                j--;
            }
        }
        return s;
    }
    bool isVowels(char c)
    {
        if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
            return true;
        return false;
    }
};