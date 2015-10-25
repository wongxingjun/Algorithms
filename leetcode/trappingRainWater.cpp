class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2)
            return 0;
        int l=0;
        int r=n-1;
        int w=0;
        int secH=0;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                secH=max(height[l],secH);
                w+=secH-height[l];
                l++;
            }
            else
            {
                secH=max(height[r],secH);
                w+=secH-height[r];
                r--;
            }
        }
        return w;
    }
};