class Solution {
public:
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
        /*
        //This method is the same as merge sort 
        //and can get a time complexity of O(m+n)
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        ListNode* head;
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        if(cur1->val<=cur2->val)
        {
            head=cur1;
            cur1=cur1->next;
        }
        else
        {
            head=cur2;
            cur2=cur2->next;
        }
        ListNode* cur_res=head;
        
        while(cur1!=NULL&&cur2!=NULL)
        {
            if(cur1->val<=cur2->val)
            {
                cur_res->next=cur1;
                cur_res=cur1;
                cur1=cur1->next;
            }
            else
            {
                cur_res->next=cur2;
                cur_res=cur2;
                cur2=cur2->next;
            }
        }
        while(cur1!=NULL)
        {
            cur_res->next=cur1;
            cur_res=cur1;
            cur1=cur1->next;
        }
        while(cur2!=NULL)
        {
            cur_res->next=cur2;
            cur_res=cur2;
            cur2=cur2->next;
        }
        cur_res->next=NULL;
        return head;
        */
    }
};