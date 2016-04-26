class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return true;
        string _s="",r_s="";
        for(char c:s)
        {
            if(c>='a'&&c<='z')
                _s.insert(_s.end(),c);
            else if(c>='A'&&c<='Z')
                _s.insert(_s.end(),c+32);
            else if(c>='0'&&c<='9')
                _s.insert(_s.end(),c);
            else continue;
        }
        if(_s.size()==0)
            return true;
        int i=0,j=_s.size()-1;
        while(i<=j)
        {
            if(_s[i]==_s[j])
            {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};