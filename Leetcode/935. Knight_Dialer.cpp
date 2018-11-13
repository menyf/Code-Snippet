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
	const int mod = 1000000007;
	int knightDialer(int N) {
        vector<vector<int>> t = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {},  {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
		vector<long long> dp(10, 1);
		long long res = 10;
		for (int i = 2; i <= N; i++) {
            res = 0;
			vector<long long> tmp(10, 0);
			for (int j = 0; j < 10; j++) {
				for (int k = 0; k < t[j].size(); k++) {
					tmp[j] = (tmp[j] + dp[t[j][k]]) % mod;
				}
				res = ((res + tmp[j]) % mod + mod) % mod;
			}
			swap(tmp, dp);
		}
		return res;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
//		solution->knightDialer(3);
	solution->knightDialer(161);
}
	
