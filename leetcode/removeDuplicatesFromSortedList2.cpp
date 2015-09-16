class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* cur=head->next;
        ListNode* tmp;
        if(cur->val==head->val)
        {
            while(cur&&cur->val==head->val)
                cur=cur->next;
            delete head;
            return deleteDuplicates(cur);
        }
        else
        {
            head->next=deleteDuplicates(head->next);
            return head;
        }
    }
};