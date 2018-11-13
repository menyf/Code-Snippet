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
	ListNode* swapPairs(ListNode* head) {
		
		if (head == NULL || head->next == NULL) 
			return head;
		
		ListNode* aa = head;
		ListNode* bb = head->next;
		ListNode* ans = bb;
		
		while (1) {
			ListNode* tmp = bb->next;
			bb->next = aa;
			
			if (tmp == NULL) {
				aa->next = NULL;
				break;
			}
			else if (tmp->next == NULL) {
				aa->next = tmp;
				break;
			}
			else {
				aa->next = tmp->next;
				aa = tmp;
				bb = tmp->next;
			}
			
		}
		
		return ans;	
	}
};