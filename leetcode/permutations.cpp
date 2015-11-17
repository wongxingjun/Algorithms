class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute_action(nums,0,nums.size()-1,res);
        return res;
    }
    
    void permute_action(vector<int> nums,int l,int r,vector<vector<int>>& permutations)
    {
        int i;
        if(l==r)
            permutations.push_back(nums);
        else
        {
            for(i=l;i<=r;i++)
            {
                swap(nums[i],nums[l]);
                permute_action(nums,l+1,r,permutations);
                swap(nums[i],nums[l]);
            }
        }
    }
};