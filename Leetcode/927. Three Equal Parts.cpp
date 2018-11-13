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
#define debug(x) cout<<"Debug : === "<<x<<" ==="<<endl;
#define debug2(x,y) cout<<"Debug : === "<<x<<" , "<<y<<" ==="<<endl;
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
	int trail(int l, int r, vector<int>& A){
		for (int i = l; i < r; i++) 
			if (A[i]) 
				return i;
		return r;
	}
	
	bool cmp(int l1, int r1, int l2, int r2, vector<int>& A){
		while (l1 < r1) 
			if (A[l1++] != A[l2++]) return false;
		return true;
	}
	
	vector<int> threeEqualParts(vector<int>& A) {
		int n = A.size();
		int cnt = count(A.begin(), A.end(), 1);
		if (cnt == 0) return {0, n - 1};
		else if (cnt % 3) return {-1, -1};
		
		int l1 = trail(0, n, A);
		int r3 = n;
		int len = n - l1;
		len /= 3;
		while (len) {
			int r1 = l1 + len;
			int l3 = n - len;
			// substring1 and substring3 are different.
			if (!cmp(l1, r1, l3, r3, A)) {
				len--;
				continue;
			}
			
			// trail 0 ahead of substring2
			int l2 = trail(r1, l3, A);
			
			// if substring2 is all zero
			if (l2 == l3 || l2 + len > l3) {
				len--;
				continue;
			}
			
			// substring1 and substring2 are different.
			if (!cmp(l1, r1, l2, l2+len, A)) {
				len--;
				continue;
			}
			
			// make sure no 1 between substring2 and substring3
			if (trail(l2+len, l3, A) == l3) {
				return {r1 - 1, l2 + len};
			}
			len--;
		}
		
		return {-1, -1};
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
//	int a[] = {0,1,0,1,1};
	vector<int>v({0,0,1,1,1,1,0,1,1,0,0,1,0,0,0,1,0,0,1,1,0,0,1,0,1});
	vector<int>ans = solution->threeEqualParts(v);
	debug2(ans[0], ans[1]);
}
	
