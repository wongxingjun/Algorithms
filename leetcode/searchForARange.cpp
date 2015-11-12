class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0]=-1;
        res[1]=-1;
        int i=0;
        for(;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                res[0]=i;
                break;
            }
        }
        i=nums.size()-1;
        for(;i>=0;i--)
        {
            if(nums[i]==target)
            {
                res[1]=i;
                break;
            }
        }

        return res;
    }
};