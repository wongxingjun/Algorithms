class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int i;
        int num=pow(2,n);
        for(i=0;i<num;i++)
        {
            int gray=(i>>1)^i;
            res.push_back(gray);
        }
        return res;
    }
};