/*Binary Tree Preorder Traversal*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> tmp;
        TreeNode* p=root;
        while(!tmp.empty()||p)
        {
            while(p)
            {
                res.push_back(p->val);
                tmp.push(p);
                p=p->left;
            }
            if(!tmp.empty())
            {
                p=tmp.top();
                tmp.pop();
                p=p->right;
            }
        }
        return res;
    }
};