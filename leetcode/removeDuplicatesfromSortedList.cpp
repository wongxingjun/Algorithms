class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        ListNode* next_next;
        if(cur==NULL)
            return head;
        while(cur->next!=NULL)
        {
            if(cur->val==cur->next->val)
            {
                next_next=cur->next->next;
                cur->next=next_next;
            }
            else
            {
                cur=cur->next;
            }
        }
        return head;
    }
};