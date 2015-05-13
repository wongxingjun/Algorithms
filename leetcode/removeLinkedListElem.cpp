/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
	public:
		ListNode* removeElements(ListNode* head, int val) {
			if(head==NULL)
				return NULL;
			ListNode *res = head;  
			ListNode *p = head;  
			while (p && p->val == val)  
			{  
				ListNode *temp = p;  
				p = p->next;  
				delete temp;  
			}  
			res = p;  

			while (p)  
			{  
				if (p->next && p->next->val == val)  
				{  
					ListNode *temp = p->next;  
					p->next = p->next->next;  
					delete temp;  
					continue;  
				}  
				p = p->next;  
			}  

			return res;  

		}
};
