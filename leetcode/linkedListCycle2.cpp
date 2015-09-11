class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head==NULL)
            return head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        if(fast==NULL||fast->next==NULL)
            return NULL;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};