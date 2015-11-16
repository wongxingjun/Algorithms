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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        findPath(root,sum,path,paths);
        return paths;
    }
    
    void findPath(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths)
    {
        if(!root)
            return;
        path.push_back(root->val);
        if(!(root->left)&&!(root->right)&&root->val==sum)
            paths.push_back(path);
        findPath(root->left,sum-root->val,path,paths);
        findPath(root->right,sum-root->val,path,paths);
        path.pop_back();
    }
};