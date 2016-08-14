#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& nums, int n, int i)
{
    int root = i;
    int left = 2*i+1;
    int right = left+1;

    if(left<n&&nums[left]>nums[root])
        root=left;
    if(right<n&&nums[right]>nums[root])
        root=right;

    if(root!=i)
    {
        swap(nums[i],nums[root]);
        heapify(nums, n, root);
    }
}

void heapSort(vector<int>& nums)
{
    int n=nums.size();
    for(int i=n/2-1;i>=0;i--)
        heapify(nums,n,i);
    for(int i=n-1;i>=0;i--)
    {
        swap(nums[0],nums[i]);
        heapify(nums,i,0);
    }
}

int main()
{
    vector<int> nums = {0,12,32,9,-4,26,7};
    heapSort(nums);
    for(int i:nums)
        cout<<i<<endl;
    return 0;
}
