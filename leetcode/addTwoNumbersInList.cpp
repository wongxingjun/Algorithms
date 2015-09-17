class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* longer;
        ListNode* shorter;
        if(len(l1)>len(l2))
        {
            longer=l1;
            shorter=l2;
        }
        else
        {
            longer=l2;
            shorter=l1;
        }
        int cnt=0;
        int tmp=0;
        ListNode* sum=longer;
        if(len(longer)==0||(len(longer)==1&&len(shorter)==0))
            return longer;
        while(shorter)
        {
            longer->val+=shorter->val;
            longer=longer->next;
            shorter=shorter->next;
        }
        ListNode* cur=sum;
        if(cur->next==NULL)
        {
            if(cur->val>=10)
            {
                cnt=cur->val/10;
                cur->val%=10;
                ListNode* tail=new ListNode(cnt);
                //tail->val=cnt;
                cur->next=tail;
                tail->next=NULL;
                return sum;
            }
            else
                return sum;
            
        }
        while(cur->next)
        {
            tmp=(cur->val+cnt)%10;
            cnt=(cur->val+cnt)/10;
            cur->val=tmp;
            cur=cur->next;
        }
        if(cnt+cur->val>=10)
        {
            tmp=(cur->val+cnt)%10;
            cnt=(cur->val+cnt)/10;
            cur->val=tmp;
            ListNode* tail=new ListNode(cnt);
            //tail->val=cnt;
            cur->next=tail;
            tail->next=NULL;
        }
        else
            cur->val+=cnt;
        return sum;
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