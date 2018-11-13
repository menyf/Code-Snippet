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
	int trap(vector<int>& height) {
		
		// Solution 1: Brute Force
//		int mx = -1, ans = 0;
//		for (int i = 0; i < height.size(); i++) {
//			mx = max(mx, height[i]);
//		}
//		for (int i = 1; i <= mx; i++) {
//			int pre = -1;
//			while (height[++pre] < i);
//			int nex = pre + 1;
//			while (nex < height.size()) {
//				if (height[nex] >= i) {
//					ans += nex - pre - 1;
//					pre = nex;
//				}
//				nex++;
//			}
//		}
//		return ans;

		// Solution 2: DP
		// dp[i]表示第i个区域左侧的壁垒的最大高度
		int mx = 0, n = height.size(), res = 0;
		vector<int> dp(n, 0);
		for (int i = 0; i < n; i++) {
			dp[i] = mx;
			mx = max(mx, height[i]);
		}
		mx = 0;
		// mx表示反向遍历的时候右侧壁垒的最大高度
		// h表示左右两个壁垒的较低者高度
		// h-height[i]表示比当前的高度高的值
		// 累计每个区域高的值，即可求出总量
		for (int i = n - 1; i >= 0; i--) {
			int h = min(dp[i], mx);
			mx = max(mx, height[i]);
			if (height[i] < h) {
				res += h - height[i];
			}
		}
		return res;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}