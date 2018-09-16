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
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
//// Answers below
typedef long long ll;
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		map<RandomListNode *, int> node_map;
		vector<RandomListNode *> node_vec;
		RandomListNode *ptr = head;
		int i = 0;
		while (ptr) {
			node_vec.push_back(new RandomListNode(ptr->label));
			node_map[ptr] = i++;
			ptr = ptr->next;
		}
		ptr = head;
		node_vec.push_back(0);
		i = 0;
		while (ptr) {
			node_vec[i]->next = node_vec[i+1];
			if (ptr->random) {
				int id = node_map[ptr->random];
				node_vec[i]->random = node_vec[id];
			}
			ptr = ptr->next;
			i++;
		}
		return node_vec[0];
	}
}; 
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}