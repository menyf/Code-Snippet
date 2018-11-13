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
		ListNode* prev = NULL;
		ListNode* ans = bb;
		
		while (aa != NULL && bb != NULL) {
			aa->next = bb->next;
			bb->next = aa;
			if (prev != NULL) {
				prev->next = bb;
			}
			if (aa->next == NULL) {
				break;
			}
			prev = aa;
			bb = aa->next->next;
			aa = aa->next;
		}
		
		return ans;	
	}
};