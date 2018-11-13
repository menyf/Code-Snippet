
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
	int partitionDisjoint(vector<int>& A) {
		int n = A.size();
		vector<int> fwd(n);
		vector<int> bwd(n);
		
		fwd[0] = A[0];
		bwd[n-1] = A[n-1];
		for (int i = 1 ; i < n; i++) {
			fwd[i] = max(fwd[i-1], A[i]);
		}
		for (int i = n - 2; i >= 0; i--) {
			bwd[i] = min(bwd[i+1], A[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			if (fwd[i] <= bwd[i+1]) {
				return i + 1;
			}
		}
		return 0;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	int a[] = {1,1,1,0,6,12};
	vector<int>v(a, a+6);
	debug(solution->partitionDisjoint(v));
}