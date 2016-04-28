class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int reach=0;
        for(int i=0;i<n;i++)
        {
            if(i>reach) return false;
            else if(nums[i]+i>reach)
                reach=nums[i]+i;
        }
        return true;
    }
};