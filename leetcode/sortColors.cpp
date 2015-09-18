class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0=0;
        int n1=0;
        int n2=0;
        int size=nums.size();
        int i=0;
        while(i<size)
        {
            if(nums[i]==0)
                n0++;
            else if(nums[i]==1)
                n1++;
            else
                n2++;
            i++;
        }
        i=0;
        while(i<n0)
        {
            nums[i]=0;
            i++;
        }
        while(i<n1+n0)
        {
            nums[i]=1;
            i++;
        }
        while(i<size)
        {
            nums[i]=2;
            i++;
        }
    }
};