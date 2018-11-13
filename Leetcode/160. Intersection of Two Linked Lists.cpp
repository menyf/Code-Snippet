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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		
		/* Solution 1: 时间复杂度nlogn, 空间复杂度n
		set<ListNode *> st;
		while (headA) {
			st.insert(headA);
			headA = headA->next;
		}
		while (headB) {
			if (st.find(headB) != st.end()) {
				return headB;
			}
			headB = headB->next;
		}
		return NULL;
		*/
		
		// Solution 2: 时间复杂度O(n), 空间复杂度O(1)
		ListNode *now = headA;
		int len_a = 0;
		while (now) {
			len_a++;
			now = now->next;
		}
		
		now = headB;
		int len_b = 0;
		while (now) {
			len_b++;
			now = now->next;
		}
		
		int len = 0;
		if (len_a > len_b) {
			int diff = len_a - len_b;
			len = len_b;
			while (diff--) {
				headA = headA->next;
			}
		}
		else {
			int diff = len_b - len_a;
			len = len_a;
			while (diff--) {
				headB = headB->next;
			}
		}
		
		while (len--) {
			if (headA == headB) {
				return headA;
			}
			else {
				headA = headA->next;
				headB = headB->next;
			}
		}
		return NULL;
		
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}