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
	string addBinary(string a, string b) {
		string ans;
		int len_a = a.size();
		int len_b = b.size();
		int co = 0;
		while (len_a && len_b) {
			int va = a[--len_a] - '0';
			int vb = b[--len_b] - '0';
			ans += '0' + (va+vb+co)%2;
			if (va + vb + co >= 2) co = 1;
			else co = 0;
		}
		while (len_a) {
			int va = a[--len_a] - '0';
			ans += '0' + (va+co)%2;
			if (va  + co >= 2) co = 1;
			else co = 0;
		}
		while (len_b) {
			int vb = b[--len_b] - '0';
			ans += '0' + (vb+co)%2;
			if (vb  + co >= 2) co = 1;
			else co = 0;
		}
		if (co) {
			ans += '1';
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}