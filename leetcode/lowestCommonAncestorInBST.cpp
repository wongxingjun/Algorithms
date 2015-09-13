class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur=root;
        while(cur!=NULL)
        {
            if(cur->val>p->val&&cur->val>q->val)
                cur=cur->left;
            else if(cur->val<p->val&&cur->val<q->val)
                cur=cur->right;
            else
                return cur;
        }
        return cur;
    }
};