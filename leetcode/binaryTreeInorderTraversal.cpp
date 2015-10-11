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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> tmp;
        TreeNode* p=root;
        while(!tmp.empty()||p)
        {
            while(p)
            {
                tmp.push(p);
                p=p->left;
            }
            if(!tmp.empty())
            {
                p=tmp.top();
                tmp.pop();
                res.push_back(p->val);
                p=p->right;
            }
        }
        return res;
    }
};