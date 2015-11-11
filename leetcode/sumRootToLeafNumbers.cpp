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
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> nums;
        if(root==NULL)
            return 0;
        vector<int> path;
        GetPath(path,root,&nums);
        int i,j;
        int sum=0;
        for(i=0;i<nums.size();i++)
        {
            int tmpSum=0;
            for(j=0;j<nums[i].size();j++)
            {
                tmpSum+=nums[i][j];
                if(j<nums[i].size()-1)
                    tmpSum*=10;
            }
            sum+=tmpSum;
        }
        return sum;
    }
    
    void GetPath(vector<int> path, TreeNode* node, vector<vector<int>>* nums)
    {
        if(node==NULL)
            return;
        path.push_back(node->val);
        if(node->left==NULL&&node->right==NULL)
            nums->push_back(path);
        else
        {
            GetPath(path,node->left,nums);
            GetPath(path,node->right,nums);
        }
    }
};