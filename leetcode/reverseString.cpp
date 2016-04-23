class Solution {
public:
    string reverseString(string s) {
        int i=s.size()-1;
        string res="";
        while(i>=0)
        {
            res.push_back(s[i]);
            i--;
        }
        return res;
    }
};