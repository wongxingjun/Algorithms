class Solution {
public:
    /*
    //Time Limit Exceeded
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* tail=getTail(head);
        ListNode* newStart=NULL;
        ListNode* newEnd=NULL;
        ListNode* pivot=partition(head,tail,&newStart,&newEnd);
        //return pivot;
        if(newStart!=pivot)
        {
            ListNode* tmp=newStart;
            while(tmp->next!=pivot)
                tmp=tmp->next;
            tmp->next=NULL;
            newStart=sortList(newStart);
            tmp=getTail(newStart);
            tmp->next=pivot;
        }
        pivot->next=sortList(pivot->next);
        return newStart;
    }
    
    ListNode* getTail(ListNode* head)
    {
        ListNode* tail=head;
        while(tail->next)
            tail=tail->next;
        return tail;
    }
    ListNode* partition(ListNode* start, ListNode* end, ListNode** newStart, ListNode** newEnd)
    {
        ListNode* pivot=end;
        ListNode* pre=NULL;
        ListNode* cur=start;
        ListNode* tail=pivot;
        ListNode* tmp;
        while(cur!=pivot)
        {
            if(cur->val<pivot->val)
            {
                if(*newStart==NULL)
                    *newStart=cur;
                pre=cur;
                cur=cur->next;
            }
            else
            {
                if(pre)
                    pre->next=cur->next;
                tmp=cur->next;
                cur->next=NULL;
                tail->next=cur;
                tail=cur;
                cur=tmp;
            }
        }
        if(*newStart==NULL)
            *newStart=pivot;
        *newEnd=tail;
        return pivot;
    }
    */
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=head;
        ListNode* q=head;
        ListNode* pre=NULL;
        while(p&&p->next)
        {
            p=p->next->next;
            pre=q;
            q=q->next;
        }
        pre->next=NULL;
        //return q;
        ListNode* l=sortList(head);
        ListNode* r=sortList(q);
        return mergeTwoLists(l,r);
    }
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        ListNode* head;
        if(l1->val<=l2->val)
        {
            head=l1;
            head->next=mergeTwoLists(l1->next,l2);
        }
        else
        {
            head=l2;
            head->next=mergeTwoLists(l1,l2->next);
        }
        return head;
    }
};