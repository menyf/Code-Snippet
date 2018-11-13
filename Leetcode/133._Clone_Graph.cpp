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
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		unordered_map<UndirectedGraphNode *, UndirectedGraphNode*>mp;
		queue<UndirectedGraphNode*>q;
		q.push(node);
		UndirectedGraphNode *rt = new Node(root->label);
		mp[node] = rt;
		while (!q.empty()) {
			UndirectedGraphNode * tmp = q.front();
			q.pop();
			for(int i = 0; i < tmp->neighbors.size(); i++) {
				if(mp.count(tmp->neighbors[i])){
					mp[tmp]->neighbors.push_back(mp[tmp->neighbors[i]]);
				}
				else {
					UndirectedGraphNode *adj = new UndirectedGraphNode(tmp->neighbors[i]->label);
					mp[tmp]->neighbors.push_back(adj);
					mp[tmp->neighbors[i]] = adj;
					q.push(tmp->neighbors[i]);
				}
			}
		}	
		return rt;	
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
