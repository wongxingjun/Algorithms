/**
 *   Definition for singly-linked list.
 *   struct ListNode {
 *      int val;
 *      ListNode *next;
 *      ListNode(int x) : val(x), next(NULL) {}
 *      };
 **/
class Solution {
	public:
		ListNode* reverseList(ListNode* head) {
			if(head==NULL)
				return NULL;
			else if(head->next==NULL)
				return head;
			else{
				ListNode* p=head;
				ListNode* q=head->next;
				ListNode* r=head->next;
				head->next=NULL;
				if(q->next==NULL)
				{
					q->next=head;
					return q;
				}
				while(q->next!=NULL)
				{
					q=q->next;
					r->next=p;
					p=r;
					r=q;
				}
				q->next=p;
				return q;
			}
		}
};
