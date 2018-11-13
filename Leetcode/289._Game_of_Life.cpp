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
class Solution {
public:
	
	bool inmap(int x, int y, int n, int m){
		return x >= 0 && x < n && y >= 0 && y < m;
	}
	
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty() || board[0].empty()) {
			return;
		}
		int n = board.size(), m = board[0].size();
		int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
		int dy[] = {0, -1, 1, 1, -1, 0, 1, -1};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					if (inmap(tx, ty, n, m) && board[tx][ty] % 2) {
						cnt++;
					}
				}
				if (board[i][j] % 2 && cnt == 2 || cnt == 3) {
					board[i][j] += 2;
				}
				else if (board[i][j] % 2 == 0 && cnt == 3) {
					board[i][j] += 2;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board[i][j] /= 2;
			}
		}
		return;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
