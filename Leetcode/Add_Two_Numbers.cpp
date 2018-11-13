#include <unordered_map>
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
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class NestedInteger {
  public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int tot = l1->val + l2->val;
		int ci = tot / 10;
		ListNode *ans = new ListNode(tot % 10);
		ListNode *head = ans;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 || l2) {
			if (!l1) {
				tot = ci + l2->val;
				ci = tot / 10;
				head->next = new ListNode(tot % 10);
				l2 = l2->next;
			}
			else if (!l2) {
				tot = ci + l1->val;
				ci = tot / 10;
				head->next = new ListNode(tot % 10);			
				l1 = l1->next;
			}
			else {
				tot = ci + l2->val + l1->val;
				ci = tot / 10;
				head->next = new ListNode(tot % 10);
				l1 = l1->next;
				l2 = l2->next;
			}
			head = head->next;
		}
		if (ci) {
			head->next = new ListNode (1);
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
