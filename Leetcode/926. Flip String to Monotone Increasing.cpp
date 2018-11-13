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
	int minFlipsMonoIncr(string S) {
		vector<int> fwd(S.size(), 0);
		vector<int> bwd(S.size(), 0);
		fwd[0] = S[0] == '1' ? 1 : 0;
		for (int i = 1; i < S.length(); i++) {
			fwd[i] = fwd[i-1] + (S[i] == '1' ? 1 : 0);
		}
		bwd.back() = S.back() == '0' ? 1 : 0;
		for (int i = S.length() - 2; i >= 0; i--) {
			bwd[i] = bwd[i + 1] + (S[i] == '0' ? 1 : 0);
		}
		int ans = min(bwd[0], fwd.back());
		for (int i = 0; i < S.length()-1; i++) {
			ans = min(ans, fwd[i] + bwd[i+1]);
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
