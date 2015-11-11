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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int> curLevel;
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        int i=1;
        while(i<=height(root))
        {
            traversal(root,i++,&curLevel);
            res.push_back(curLevel);
            curLevel.erase(curLevel.begin(),curLevel.end());
        }
        return res;
    }
    
    int height(TreeNode* node)
    {
        if(node==NULL)
            return 0;
        else
            return max(height(node->left),height(node->right))+1;
    }
    
    void traversal(TreeNode* node, int level, vector<int>* curLevel)
    {
        if(node==NULL)
            return;
        if(level==1)
            curLevel->push_back(node->val);
        else
        {
            traversal(node->left,level-1,curLevel);
            traversal(node->right,level-1,curLevel);
        }
    }
    
};