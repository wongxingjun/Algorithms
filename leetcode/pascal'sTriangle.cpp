class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows<=0)
            return res;
        vector<int> level1={1};
        vector<int> level2={1,1};
        res.push_back(level1);
        if(numRows==1) return res;
        res.push_back(level2);
        if(numRows==2) return res;
        int level=3;
        vector<int> preLevel=level2;
        vector<int> curLevel;
        for(;level<=numRows;level++)
        {
            int i=1;
            curLevel.push_back(1);
            for(;i<level-1;i++)
                curLevel.push_back(preLevel[i-1]+preLevel[i]);
            curLevel.push_back(1);
            res.push_back(curLevel);
            preLevel=curLevel;
            curLevel.erase(curLevel.begin(),curLevel.end());
        }
        return res;
    }
};



//Simpified version
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows<=0)
            return res;
        int level=1;
        vector<int> preLevel={};
        vector<int> curLevel;
        for(;level<=numRows;level++)
        {
            int i=1;
            curLevel.push_back(1);
            for(;i<level-1;i++)
                curLevel.push_back(preLevel[i-1]+preLevel[i]);
            if(level>1)
                curLevel.push_back(1);
            res.push_back(curLevel);
            preLevel=curLevel;
            curLevel.erase(curLevel.begin(),curLevel.end());
        }
        return res;
    }
};