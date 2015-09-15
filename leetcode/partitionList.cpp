class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=head;
        ListNode l(0);
        ListNode r(0);
        ListNode* left=&l;
        ListNode* right=&r;
        while(p)
        {
            if(p->val<x)
            {
                left->next=p;
                left=p;
                p=p->next;
            }
            else
            {
                right->next=p;
                right=p;
                p=p->next;
            }
        }
        left->next=r.next;
        right->next=NULL;
        return l.next;
    }
};