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
	vector<vector<int>> vis;
	int n;
	int m;
	
	bool inmap(int x, int y){
		return x >= 0 && y >= 0 && x < n && y < m;
	}
	
	bool dfs(vector<vector<char>>& board, int x, int y, int pos, string& word){
		if (pos == word.length()) return true;
		vis[x][y] = 1;
		int dx[] = {0, 0, 1, -1};
		int dy[] = {1, -1, 0, 0};
		for (int i = 0; i < 4; i++) {
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (inmap(tx, ty) && !vis[tx][ty] && board[tx][ty] == word[pos] && dfs(board, tx, ty, pos + 1,  word)) {
				return true;
			}
		}
		vis[x][y] = 0;
		return false;
	}
	
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || board[0].size() == 0) 
			return false;
		n = board.size();
		m = board[0].size();
		vis.resize(n);
		for (int i = 0; i < n; i++) {
			vis[i].resize(m);
			for (int j = 0; j < m; j++) {
				vis[i][j] = 0;
			}
		}
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == word[0] && dfs(board, i, j, 1, word)) {
					return true;
				}
			}
		}
		return false;
		
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
