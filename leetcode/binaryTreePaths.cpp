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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL)
            return res;
        string path="";
        GetPath(path,root,&res);
        return res;
    }
    
    void GetPath(string path, TreeNode* node, vector<string>* res)
    {
        if(node==NULL)
            return;
        if(!path.empty())
            path+="->"+to_string(node->val);
        else
            path+=to_string(node->val);
        if(node->left==NULL&&node->right==NULL)
            res->push_back(path);
        else
        {
            GetPath(path,node->left,res);
            GetPath(path,node->right,res);
        }
    }
};