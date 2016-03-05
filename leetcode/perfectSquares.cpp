class Solution {
public:
    int numSquares(int n) {
        if(n<=0) return 0;
        vector<int> cnt(n+1,INT_MAX);
        cnt[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
                cnt[i]=min(cnt[i],cnt[i-j*j]+1);
        }
        return cnt.back();
    }
};