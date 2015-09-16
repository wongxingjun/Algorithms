class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        stack<int> s;
        ListNode* cur=head;
        while(cur)
        {
            s.push(cur->val);
            cur=cur->next;
        }
        cur=head;
        int tmp;
        s.top();
        while(cur)
        {
            if(cur->val!=s.top())
                return false;
            else
            {
                cur=cur->next;
                s.pop();
            }
        }
        return true;
        
    }
};