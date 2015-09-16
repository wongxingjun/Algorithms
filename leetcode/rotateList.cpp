class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)
            return head;
        int len=0;
        ListNode* cur=head;
        while(cur)
        {
            len++;
            cur=cur->next;
        }
        k=k%len;
        if(k==0)
            return head;
        ListNode* res;
        cur=head;
        int i=0;
        while(i<len-k-1)
        {
            cur=cur->next;
            i++;
        }
        ListNode* rotate=cur->next;
        cur->next=NULL;
        res=rotate;
        cur=rotate;
        while(cur->next)
            cur=cur->next;
        cur->next=head;
        return res;
    }
    
};