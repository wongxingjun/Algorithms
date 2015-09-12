class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* tmp=head;
        if(head==NULL)
            return head;
        while(tmp!=NULL)
        {
            tmp=tmp->next;
            len++;
        }
        int del=len-n;
        if(del==0)
            return head->next;
        if(del==1)
        {
            head->next=head->next->next;
            return head;
        }
        int i=1;
        tmp=head;
        while(i<=del-1)
        {
            tmp=tmp->next;
            i++;
        }
        tmp->next=tmp->next->next;
        return head;
    }
};