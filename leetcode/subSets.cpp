class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),std::greater<int>());
        return subsets_fun(nums,0,n);
    }
    vector<vector<int>> subsets_fun(vector<int>& nums, int id, int n)
    {
        vector<vector<int>> subsets;
        if(id==n)
        {
            vector<int> subset;
            subsets.push_back(subset);
        }
        else
        {
            vector<vector<int>> sub_subsets=subsets_fun(nums, id+1, n);
            int cur_element=nums[id];
            for(int i=0;i<sub_subsets.size();i++)
            {
                vector<int> subset=sub_subsets[i];
                subsets.push_back(subset);
                subset.push_back(cur_element);
                subsets.push_back(subset);
            }
        }
        return subsets;
    }
};