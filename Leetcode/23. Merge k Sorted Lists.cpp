/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool cmp(const ListNode *a, const ListNode *b) {
		return a->val < b->val;
		
		// sort(v.begin(), v.end(), cmp);
	}
class Solution {
public:
	
	bool isExistence(vector<ListNode*>& lists){
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL) return true;
		}
		return false;
	}
	
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
	
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		
		/* Solution 1
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
		*/
		
		/* Solution 2: Sort*/
//		vector<ListNode *> node_vec;
//		for (int i = 0; i < lists.size(); i++) {
//			ListNode *head = lists[i];
//			while (head) {
//				node_vec.push_back(head);
//				head = head->next;
//			}
//			
//		}
//		
//        if (node_vec.size() == 0) {
//			return NULL;
//		}
//		sort(node_vec.begin(), node_vec.end(), cmp);
//		for (int i = 1; i < node_vec.size(); i++) {
//			node_vec[i-1]->next = node_vec[i];
//		}
//		node_vec[node_vec.size() - 1]->next = NULL;
//		return node_vec[0];

		/* Solution 3: Sort*/
		if (lists.size() == 0) {
			return NULL;
		}
		
		if (lists.size() == 1) {
			return lists[0];
		}
		
		if (lists.size() == 2) {
			return mergeTwoLists(lists[0], lists[1]);
		}
		
		int mid = (int)lists.size()/2;
		
		vector<ListNode *> sub1_lists;
		vector<ListNode *> sub2_lists;
		for (int i = 0; i < mid ; i++) {
			sub1_lists.push_back(lists[i]);
		}
		for (int i = mid; i < lists.size(); i++) {
			sub2_lists.push_back(lists[i]);
		}
		ListNode* l1 = mergeKLists(sub1_lists);
		ListNode* l2 = mergeKLists(sub2_lists);
		return mergeTwoLists(l1, l2);
	}
};