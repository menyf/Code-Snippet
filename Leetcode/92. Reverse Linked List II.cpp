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
//// Answers above
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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		int change_len = n - m + 1; // 计算需要逆置的节点个数
		ListNode *pre_head = NULL: // 初始化开始逆置的节点的前驱
		ListNode *result = head; // 最终转换后的链表头结点，非特殊情况即为head
		while (head && --m) {
			pre_head = head;
			head = head->next;
		}
		ListNode *modify_list_tail = head;
		ListNode *new_head = NULL;
		while (head && change_len) {
			ListNode *next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
			change_len--;
		}
		modify_list_tail->next = head;
		if (pre_head) {
			pre_head->next = new_head;
		}
		else {
			result = new_head;
		}
		return result;
		
		// Practice.
//		int len = n - m + 1;
//		ListNode* rt = head;
//		ListNode* pre_ptr = NULL;
//		while (head && --m) {
//			pre_ptr = head;
//			head = head->next;
//		}
//		ListNode* new_head = NULL;
//		ListNode* new_tail = head;
//		while (head && len--) {
//			ListNode* next = head->next;
//			head->next = new_head;
//			new_head = head;
//			head = next;
//		}
//		new_tail->next = head;
//		if (pre_ptr == NULL) {
//			return new_head;
//		}
//		else {
//			pre_ptr->next = new_head;
//		}
//
//		return rt;

	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}