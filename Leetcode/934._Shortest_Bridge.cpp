#include <unordered_map>
#include <unordered_set>
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
class Solution {
public:
	bool inmap(int x, int y, int n, int m) {
		return x >= 0 && y >= 0 && x < n && y < m;
	}
	
	int shortestBridge(vector<vector<int>>& A) {
		vector<pair<int, int>> island1;
		int res = 500;
		int dx[] = {0, 0, -1, 1};
		int dy[] = {1, -1, 0, 0};
		queue<pair<int, int>>q;
		for (int i = 0 ; i < A.size() && q.empty(); i++) {
			for(int j = 0; j < A[0].size() && q.empty(); j++){
				if (A[i][j]) {
					q.push({i, j});
					A[i][j] = 0;
				}
			}
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			island1.push_back(q.front());
			q.pop();
			for (int i = 0; i < 4; i++) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (inmap(tx, ty, A.size(), A[0].size()) && A[tx][ty]) {
					A[tx][ty] = 0;
					q.push({tx, ty});
				}
			}
		}
		for (int i = 0 ; i < A.size(); i++) {
			for(int j = 0; j < A[0].size(); j++){
				if (A[i][j]) {
					for (int k = 0; k < island1.size(); k++) {
						int dis = max(island1[k].first - i, i - island1[k].first) + max(island1[k].second - j, j - island1[k].second);
						res = min(dis, res);
					}
				}
			}
		}
		return res;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
