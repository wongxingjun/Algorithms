class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0,k=0;
        vector<int> tmp(m+n);
        while(i<m&&j<n)
        {
            if(nums1[i]<nums2[j])
            {
                tmp[k]=nums1[i];
                i++;
                k++;
            }
            else
            {
                tmp[k]=nums2[j];
                j++;
                k++;
            }
        }
        while(i<m)
        {
            tmp[k]=nums1[i];
            i++;
            k++;
        }
        while(j<n)
        {
            tmp[k]=nums2[j];
            j++;
            k++;
        }
        for(i=0;i<m+n;i++)
            nums1[i]=tmp[i];
    }
};