class Solution {
public:
    string countAndSay(int n) {
        string res;
        if(n==1)
        {
            res="1";
            return res;
        }
        string s=countAndSay(n-1);
        int i=0;
        while(i<s.size())
        {
            char num=s[i];
            int cnt=1;
            while(s[i+1]==num)
            {
                cnt++;
                i++;
            }
            i++;
            res.push_back(cnt+'0');
            res.push_back(num);
        }
        return res;
    }
};