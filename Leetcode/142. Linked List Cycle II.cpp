#include <iostream>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
//// Answers below
typedef long long ll;
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		// Solution 1
//		set<ListNode*> node_set;
//		while (head) {
//			if (node_set.find(head) == node_set.end()) {
//				node_set.insert(head);
//			}
//			else {
//				return head;
//			}
//			head = head->next;
//		}
//		return 0;
		
		// Solution 2: 快慢指针
		ListNode *fast_node = head;
		ListNode *slow_node = head;
		ListNode *meet = NULL;
		while (fast_node) {
			slow_node = slow_node->next;
			fast_node = fast_node->next;
			if (!fast_node) break;
			fast_node = fast_node->next;
			if (fast_node == slow_node) {
				meet = fast_node;
				break;
			}
		}
		
		if (meet == NULL) {
			return NULL;
		}
		
		while (head) {
			if (fast_node == head) {
				return head;
			}
			fast_node = fast_node->next;
			head = head->next;
		}
		return NULL;


		//Practice
//		if (!head) return NULL;
//		ListNode* fast = head;
//		ListNode* slow = head;
//		ListNode* meet = NULL;
//		while (fast) {
//			fast = fast->next;
//			slow = slow->next;
//			if (fast) {
//				fast = fast->next;
//			}
//			else {
//				return NULL;
//			}
//			if (fast == slow) {
//				meet = fast;
//				break;
//			}
//		}
//		
//		if (!meet) {
//			return NULL;
//		}
//		
//		while (head) {
//			if (head == meet) {
//				return head;
//			}
//			else {
//				head = head->next;
//				meet = meet->next;
//			}
//		}
//		
//		return NULL;

	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}