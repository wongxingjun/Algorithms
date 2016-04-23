class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res,"",n,0);
        return res;
    }
    
    void helper(vector<string>& res,string s,int l,int r)
    {
        if(l==0&&r==0) 
            res.push_back(s);
        if(r>0) helper(res,s+')',l,r-1);
        if(l>0) helper(res,s+'(',l-1,r+1);
    }
};