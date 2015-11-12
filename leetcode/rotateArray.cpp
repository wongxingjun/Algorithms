class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=1||k%n==0)
            return;
        k=k%n;
        int i=n-k;
        vector<int> tmp;
        for(;i<n;i++)
            tmp.push_back(nums[i]);
        auto it=nums.begin();
        i=0;
        while(i<n-k)
        {
            it++;
            i++;
        }
        nums.erase(it,nums.end());
        i=tmp.size()-1;
        for(;i>=0;i--)
        {
            it=nums.begin();
            nums.insert(it,tmp[i]);
        }
    }
};