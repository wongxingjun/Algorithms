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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymmetricSub(root->left,root->right);
    }
    
    bool isSymmetricSub(TreeNode* l,TreeNode* r)
    {
        if(l==NULL&&r==NULL)
            return true;
        if(l==NULL||r==NULL)
            return false;
        if(l->val!=r->val)
            return false;
        return isSymmetricSub(l->left,r->right)&&isSymmetricSub(l->right,r->left);
    } 
};