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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> s;
        TreeNode* p=root;
        s.push(p);
        while(!s.empty())
        {
            p=s.top();
            s.pop();
            res.push_back(p->val);
            if(p->left)
                s.push(p->left);
            if(p->right)
                s.push(p->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};