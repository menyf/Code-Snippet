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
	
	bool isExistence(vector<ListNode*>& lists){
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL) return true;
		}
		return false;
	}
	
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		
		int val = -1;
		int idx = -1;
		bool isSet = false;
		for (int i = 0; i < lists.size(); i++) {
			ListNode* tmp = lists[i];
			if (tmp == NULL) continue;
			if (!isSet || val > tmp->val) {
				val = tmp->val;
				idx = i;
				isSet = true;
			}
		}
		if (!isSet) return NULL;
		
		ListNode* now = lists[idx];
		ListNode* ans = now;
		lists[idx] = lists[idx]->next;
		
		while (isExistence(lists)) {
			isSet = false;
			for (int i = 0; i < lists.size(); i++) {
				ListNode* tmp = lists[i];
				if (tmp == NULL) continue;
				if (!isSet || val > tmp->val) {
					val = tmp->val;
					idx = i;
					isSet = true;
				}
			}
			now->next = lists[idx];
			now = now->next;
			lists[idx] = lists[idx]->next;
		}
		
		return ans;
	}
};