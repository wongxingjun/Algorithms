class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA=headA;
        ListNode* curB=headB;
        int lenA=0;
        int lenB=0;
        if(headA==NULL||headB==NULL)
            return NULL;
        while(curA->next)
        {
            curA=curA->next;
            lenA++;
        }
        while(curB->next)
        {
            curB=curB->next;
            lenB++;
        }
        curA=headA;
        curB=headB;
        ListNode* longer;
        ListNode* shorter;
        int cnt=0;
        int i=0;
        if(lenA>=lenB)
        {
            longer=headA;
            shorter=headB;
            cnt=lenA-lenB;
        }
        else
        {
            longer=headB;
            shorter=headA;
            cnt=lenB-lenA;
        }
        while(longer!=shorter)
        {
            longer=longer->next;
            i++;
            if(i>cnt)
            {
                shorter=shorter->next;
            }
        }
        return longer;
    }
};