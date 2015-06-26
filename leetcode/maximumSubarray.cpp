/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> sum(n);
        sum[0]=A[0];
        int res=A[0];
        for(int i=1;i<n;i++)
        {
            sum[i]=max(sum[i-1]+A[i],A[i]);
            res=max(sum[i],res);
        }
        return res;
    }
};