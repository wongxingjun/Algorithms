class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex<0)
            return res;
        if(rowIndex==0)
        {
            res.push_back(1);
            return res;
        }
        int i=1;
        res.push_back(1);
        vector<int> preLevel=getRow(rowIndex-1);
        for(;i<rowIndex;i++)
            res.push_back(preLevel[i]+preLevel[i-1]);
        res.push_back(1);
    }
};