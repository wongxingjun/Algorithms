//The most silly method
class Solution {
    public:
    int findKthLargest(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            reverse(nums.begin(), nums.end());
            return nums[k-1];
        }
};

/*Other solutions:
    Max heap
    Set a window of k ints
*/
