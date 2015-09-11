class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL)
            return head;
        int tmp;
        ListNode* cur=head;
        if(cur->next==NULL)
            return head;
        if(cur->next->next==NULL)
        {
            tmp=cur->val;
            cur->val=cur->next->val;
            cur->next->val=tmp;
            return head;
        }
        while(cur->next!=NULL&&cur->next->next!=NULL)
        {
            tmp=cur->val;
            cur->val=cur->next->val;
            cur->next->val=tmp;
            cur=cur->next->next;
        }
        if(cur->next==NULL)
            return head;
        else
        {
            tmp=cur->val;
            cur->val=cur->next->val;
            cur->next->val=tmp;
            cur=cur->next->next;
            return head;
        }
    }
};