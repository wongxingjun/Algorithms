class Solution {
public:
    /*
    //Time Limit Exceeded
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        int n=nums.size();
        int l=0;
        int r=1;
        for(l=0;l<n-1;l++)
        {
            for(r=l+1;r<n;r++)
            {
                if(nums[l]+nums[r]==target)
                {
                    int tmp=min(l+1,r+1);
                    index.push_back(tmp);
                    index.push_back(l+r+2-tmp);
                }
            }
        }
        return index;
    }

    int min(int a,int b)
    {
        return a>b?b:a;
    }
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> map;
        int n=nums.size();
        int i=0;
        int find=0;
        while(i<n)
        {
            find=map[target-nums[i]];
            if(find)
            {
                res.push_back(find-1);
                res.push_back(i);
                break;
            }
            map[nums[i]]=i+1;
            i++;
        }
        return res;
    }
};
