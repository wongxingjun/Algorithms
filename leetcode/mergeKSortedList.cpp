class Solution {
public:
    //This method is right but got "Time Limit Exceeded"
    /*
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        else if(n==1)
            return lists[0];
        int i=0;
        ListNode* res=lists[0];
        for(i=1;i<n;i++)
            res=mergeTwoLists(res,lists[i]);
        return res;
        
    }
    */

    //Divide and conquer, less time is needed but still needs to be optimized 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        else if(n==1)
            return lists[0];
        int i=0;
        int mid=(n-1)/2;
        vector<ListNode*> l;
        vector<ListNode*> r;
        for(;i<mid+1;i++)
            l.push_back(lists[i]);
        for(;i<n;i++)
            r.push_back(lists[i]);
        ListNode* left=mergeKLists(l);
        ListNode* right=mergeKLists(r);
        return mergeTwoLists(left,right);
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