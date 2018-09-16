/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) {
			return l2;
		}
		if (l2 == NULL) {
			return l1;
		}
		
		ListNode* now;

		if (l1->val > l2->val) {
			now = l2;
			l2 = l2->next; 
		}
		else {
			now = l1;
			l1 = l1->next;
		}
		ListNode* ans = now;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val > l2->val ) {
				now->next = l2;
				now = l2;
				l2 = l2->next;
			}
			else {
				now->next = l1;
				now = l1;
				l1 = l1->next;
			}
		}
		
		while (l1 != NULL) {
			now->next = l1;
			now = l1;
			l1 = l1->next;
		}
		
		while (l2 != NULL) {
			now->next = l2;
			now = l2;
			l2 = l2->next;
		}
		
		return ans;
	}
};