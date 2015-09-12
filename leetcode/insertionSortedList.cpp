class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* cur=head;
        ListNode* pre=head;
        ListNode* next;
        while(pre->next!=NULL)
        {
            next=pre->next;
            if(next->val>=pre->val)
            {
                pre=pre->next;
            }
            else
            {
                pre->next=next->next;
                if(next->val<cur->val)
                {
                    head=next;
                    next->next=cur;
                    cur=head;
                }
                else
                {
                    while(cur->next->val<next->val)
                    {
                        cur=cur->next;
                    }
                    next->next=cur->next;
                    cur->next=next;
                    cur=head;
                }
            }
        }
        return head;
        
    }
};