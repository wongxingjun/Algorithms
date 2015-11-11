/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        sideView(root,res,1);
        return res;
    }
    
    void sideView(TreeNode* node, vector<int>& res, int level)
    {
        if(node==NULL)
            return;
        if(res.size()<level)
            res.push_back(node->val);
        sideView(node->right,res,level+1);
        sideView(node->left,res,level+1);
    }
};