/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.*/
class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			if(nums.size()==0)
				return 0;
			int len=nums.size();
			vector<int>::iterator itr = nums.begin();
			while(itr!=nums.end())
			{
				if(*itr==val)
				{
					nums.erase(itr);
					len--;
				}
				else
					itr++;
			}
			return len;
		}
};
