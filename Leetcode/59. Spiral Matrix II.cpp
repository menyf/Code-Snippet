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
class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > ans(n, vector<int>(n, 0));
		int dx[] = {0, 1, 0, -1};
		int dy[] = {1, 0, -1, 0};
		int x = 0, y = 0, dir = 0;
		for (int v = 1; v <= n * n; v++) {
			ans[x][y] = v;
			x += dx[dir];
			y += dy[dir];
			if (y == n || x == n || y == -1 || ans[x][y]) {
				x += dx[(dir + 1) % 4] - dx[dir];
				y += dy[(dir + 1) % 4] - dy[dir];
				dir = (dir + 1) % 4;
			}
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	solution->generateMatrix(3);
	
}