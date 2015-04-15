/*
Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n=num.size();
        int res=num[0];
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            if(num[i]==res)
                cnt++;
            else
                cnt--;
            if(cnt==0)
            {
                cnt=1;
                res=num[i];
            }
        }
        return res;
    }
};