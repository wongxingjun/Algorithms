class Solution {
public:
    /*
    //Time Limit Exceeded, O(n*n)
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return;
        ListNode* cur=head;
        ListNode* tail;
        tail=getTail(head);
        tail->next=cur->next;
        cur->next=tail;
        reorderList(tail->next);
    }
    ListNode* getTail(ListNode* head)
    {
        ListNode* p=head;
        while(p->next->next)
            p=p->next;
        ListNode* res=p->next;
        p->next=NULL;
        return res;
    }
    */

    //O(n)
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* right=reverse(slow->next);
        slow->next=NULL;
        ListNode* l=head;
        ListNode* r=right;
        ListNode* tmp;
        //now insert r list to l list with alternate order
        while(r)
        {
            tmp=r;
            r=r->next;
            tmp->next=l->next;
            l->next=tmp;
            l=tmp->next;
        }
    }
    
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL)
            return head;
        ListNode* cur=head;
        //pre must be initialized with NULL
        ListNode* pre=NULL;
        ListNode* next;
        while(cur)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};