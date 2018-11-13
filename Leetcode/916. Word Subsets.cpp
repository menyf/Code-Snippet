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
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<string> ans;
		vector<int> alpha(26, 0);
		for (int i = 0; i < B.size(); i++) {
			vector<int> tmp(26, 0);
			for (int j = 0; j < B[i].length(); j++) {
				tmp[B[i][j] - 'a'] ++;
			}
			for (int j = 0; j < 26; j++) {
				alpha[j] = max(alpha[j], tmp[j]);
			}
		}
		for (int i = 0; i < A.size(); i++) {
			vector<int> tmp(26, 0);
			bool flag = true;
			for (int j = 0; j < A[i].length(); j++) {
				tmp[A[i][j] - 'a'] ++;
			}
			for (int j = 0; j < 26 && flag; j++) {
				if(alpha[j] && alpha[j] > tmp[j]) flag = false;
			}
			if(flag) ans.push_back(A[i]);
		}		
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
//	char ** A = {"amazon","apple","facebook","google","leetcode"};
//	char ** B = {"lo","eo"};
	vector<string> aa;
	aa.push_back("amazon");
	aa.push_back("apple");
	aa.push_back("facebook");
	aa.push_back("google");
	aa.push_back("leetcode");
	vector<string> bb;
	bb.push_back("lo");
	bb.push_back("eo");
	vector<string> ans = solution->wordSubsets(aa, bb);
	for (int i = 0; i < ans.size() ;i++) {
		debug(ans[i]);
	}
	
}