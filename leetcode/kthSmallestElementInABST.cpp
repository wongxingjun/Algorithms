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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int res=INT_MIN;
        TreeNode *cur=root;
        while(cur)
        {
            if(cur->left==NULL)
            {
                count++;
                if(count==k)
                    res=cur->val;
                cur=cur->right;
            }
            else
            {
                TreeNode *pre=cur->left;
                while(pre->right!=NULL&&pre->right!=cur)
                    pre=pre->right;
                if(pre->right==NULL)
                {
                    pre->right=cur;
                    cur=cur->left;
                }
                else
                {
                    pre->right=NULL;
                    count++;
                    if(count==k)
                        res=cur->val;
                    cur=cur->right;
                }
            }
        }
        return res;
    }
};