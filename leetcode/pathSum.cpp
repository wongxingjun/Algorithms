/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
*/
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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL)
            return false;
        else{
            if(root->left==NULL&&root->right==NULL)
                return root->val==sum;
            else if(root->left!=NULL&&root->right==NULL)
                return hasPathSum(root->left,sum-root->val);
            else if(root->left==NULL&&root->right!=NULL)
                return hasPathSum(root->right,sum-root->val);
            else
                return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
        }
    }
            
};