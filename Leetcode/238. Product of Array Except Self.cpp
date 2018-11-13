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
//// Answers below
typedef long long ll;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int>fwd(n, 0);
		vector<int>bwd(n, 0);
		vector<int>ans(n);
		for (int i = 0; i < n; i++) {
			fwd[i] = i == 0 ? nums[i] : fwd[i-1] * nums[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			bwd[i] = i == n - 1 ? nums[i] : bwd[i+1] * nums[i];
		}
		for (int i = 0; i < n ; i++) {
			if (i == 0) {
				ans[i] = bwd[1];
			}
			else if (i == n - 1) {
				ans[i] = fwd[n-2];
			}
			else {
				ans[i] = fwd[i-1] * bwd[i+1];
			}
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}