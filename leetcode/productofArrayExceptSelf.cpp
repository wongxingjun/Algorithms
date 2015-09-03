/*Product of Array Except Self*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        if(nums.size()==2)
        {
            res[0]=nums[1];
            res[1]=nums[0];
            return res;
        }
        res[0]=1;
        res[1]=nums[0];
        int i;
        for(i=2;i<res.size();i++)
            res[i]=res[i-1]*nums[i-1];
        int tmp;
        tmp=1;
        for(i=res.size()-2;i>=0;i--)
        {
            tmp*=nums[i+1];
            res[i]=tmp*res[i];
        }
        return res;
    }
};