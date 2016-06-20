class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n=nums.size();
        int i=0;
        while(i<n-1)
        {
            int a=nums[i],j=i+1,k=n-1;
            while(j<k)
            {
                int b=nums[j],c=nums[k],sum=a+b+c;
                if(sum==0)
                    res.push_back({a,b,c});
                if(sum<=0)
                    while(nums[j]==b&&j<k)
                        j++;
                if(sum>=0)
                    while(nums[k]==c&&j<k)
                        k--;
            }
            while(nums[i]==a&&i<n)
                i++;
        }
        return res;
    }
};