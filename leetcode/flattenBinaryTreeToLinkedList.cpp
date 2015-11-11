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
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        vector<int> nodes;
        traversal(root,&nodes);
        int i;
        root->val=nodes[0];
        root->left=NULL;
        TreeNode* cur=root;
        for(i=1;i<nodes.size();i++)
        {
            TreeNode* tmp=new TreeNode(nodes[i]);
            cur->right=tmp;
            cur=tmp;
        }
    }
    void traversal(TreeNode* root, vector<int>* nodes)
    {
        if(root==NULL)
            return;
        nodes->push_back(root->val);
        traversal(root->left,nodes);
        traversal(root->right,nodes);
    }
};