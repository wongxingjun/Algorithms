class Solution {
public:
    /* break the relative order between non-zero elements
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return;
        int i=0;
        int j=n-1;
        while(i!=j)
        {
            if(nums[i]==0&&nums[j]!=0)
            {
                nums[i]=nums[j];
                nums[j]=0;
            }
            else if(nums[i]!=0)
                i++;
            else if(nums[j]==0)
                j--;
        }
    }*/
    void moveZeroes(vector<int>& nums){
        int n=nums.size();
        if(n<=1)
            return;
        int i=0;
        int j=0;
        while(i<n)
        {
            if(nums[i]!=0)
            {
                nums[j++]=nums[i];
                i++;
            }
            else
                i++;
        }
        while(j<n)
        {
            nums[j]=0;
            j++;
        }
    }
};