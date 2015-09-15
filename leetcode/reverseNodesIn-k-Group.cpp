class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||len(head)<k)
            return head;
        ListNode* cur=head;
        ListNode* next;
        ListNode* pre=NULL;
        int cnt=0;
        while(cur&&cnt<k)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
            cnt++;
        }
        if(head)
            head->next=cur;
        if(cur)
            head->next=reverseKGroup(cur,k);
        return pre;
    }
    int len(ListNode* head)
    {
        int len=0;
        ListNode* p=head;
        while(p)
        {
            len++;
            p=p->next;
        }
        return len;
    }
};