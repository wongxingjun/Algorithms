class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        int i;
        for(i=1;i<n;i++)
            res^=nums[i];
        return res;
    }
};