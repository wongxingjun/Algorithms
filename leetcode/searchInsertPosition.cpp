/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0
*/
class Solution {
	public:
		int searchInsert(vector<int>& nums, int target) {
			int i=0;
			int n=nums.size();
			if(n==0)
				return 0;
			for(;i<n;i++)
				if(nums[i]==target)
					return i;
			if(i==n)
				for(int j=0;j<n;j++)
				{
					if(nums[0]>target)
						return 0;
					if(j==n-1||(nums[j]<target&&nums[j+1]>target))
						return j+1;
				}

		}
};
