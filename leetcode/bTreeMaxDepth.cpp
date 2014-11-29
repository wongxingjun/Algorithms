/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(root==NULL)
            return 0;
        int lDepth=1;
        int rDepth=1;
        lDepth+=maxDepth(root->left);
        rDepth+=maxDepth(root->right);
        return lDepth>rDepth?lDepth:rDepth;
    }
};