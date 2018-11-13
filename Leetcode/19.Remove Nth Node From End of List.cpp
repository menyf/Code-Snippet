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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if(head->next == NULL) return NULL;
		vector<ListNode*> v;
		ListNode* now = head;
		while (now != NULL) {
			v.push_back(now);
			now = now->next;
		}
		// rm the 1st
		if (n == v.size()) {
			delete v[0];
			return v[1];
		}
		int len = v.size();
		// n-1 -> n
		now = v[len-n-1]->next;
		v[len-n-1]->next = v[len-n]->next;
		delete now;
		return head;
	}
};