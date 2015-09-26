class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)
            return head;
        RandomListNode* cur=head;
        RandomListNode* tmp=NULL;
        while(cur)
        {
            tmp=new RandomListNode(cur->label);
            tmp->next=cur->next;
            cur->next=tmp;
            cur=tmp->next;
        }
        cur=head;
        while(cur)
        {
            if(cur->random)
                cur->next->random=cur->random->next;
            cur=cur->next->next;
        }
        cur=head;
        RandomListNode h(0);
        RandomListNode* cur_clone=&h;
        while(cur)
        {
            cur_clone->next=cur->next;
            cur_clone=cur_clone->next;
            cur->next=cur->next->next;
            cur=cur->next;
        }
        return h.next;
    }
};