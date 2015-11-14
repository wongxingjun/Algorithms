/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p=head;
        if(head==NULL)
            return NULL;
        int len=0;
        while(p)
        {
            len++;
            p=p->next;
        }
        if(len==1)
            return new TreeNode(head->val);
        p=head;
        int i=0;
        for(;i<len/2-1;i++)
            p=p->next;
        ListNode* mid=p->next;
        TreeNode* root=new TreeNode(mid->val);
        ListNode* l=head;
        ListNode* r=mid->next;
        p->next=nullptr;
        root->left=sortedListToBST(l);
        root->right=sortedListToBST(r);
        return root;
    }
    
};