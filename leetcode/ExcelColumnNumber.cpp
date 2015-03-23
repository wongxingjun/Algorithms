class Solution {
public:
    int titleToNumber(string s) {
        int i=0;
        int temp=1;
        int ans=0;
          for(i=s.length()-1;i>=0;i--)
          {
              ans+=(s[i]-64)*temp;
              temp*=26;
          }
        return ans;
    }
};
