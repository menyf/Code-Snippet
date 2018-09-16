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
	ListNode* partition(ListNode* head, int x) {
		ListNode less_head(0);
		ListNode more_head(0);
		ListNode *less_ptr = &less_head;
		ListNode *more_ptr = &more_head;
		while (head){
			if (head->val < x) {
				less_ptr->next = head;
				less_ptr = less_ptr->next;
			}
			else {
				more_ptr->next = head;
				more_ptr = more_ptr->next;
			}
			head = head->next;
		}
		less_ptr->next = more_head.next;
		more_ptr->next = NULL;
		return less_head.next;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}