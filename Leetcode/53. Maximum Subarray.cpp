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

// DP
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		
		vector<int>dp;
		int mx = INT_MIN;
		dp.push_back(0);
		for (int i = 0; i < nums.size(); i++) {
			if (dp[i] < 0) {
				mx = max(mx, nums[i]);
				dp.push_back(nums[i]);
			}
			else {
				int tmp = dp[i] + nums[i];
				mx = max(mx, tmp);
				dp.push_back(tmp);
			}
		}
		return mx;
		
	}
};

// Divide and conquer
class Solution {
public:
	int dc(vector<int>& nums, int l, int r){
		if (l == r)	return nums[l]; 
		
		int mid = (l + r) / 2;
		int left_sum = dc(nums, l, mid);
		int right_sum = dc(nums, mid+1, r);
		int left_max = (1<<31);
		int right_max = (1<<31);
		int sum = 0;
		for (int i = mid; i >= l; i--) {
			sum += nums[i];
			left_max = max(left_max, sum);
		}
		sum = 0;
		for (int i = mid + 1; i <= r ; i++) {
			sum += nums[i];
			right_max = max(sum, right_max);
		}
		sum = left_max + right_max;
		sum = max(sum, left_sum);
		sum = max(sum, right_sum);
		return sum;

	}
	
	int maxSubArray(vector<int>& nums) {
		return dc(nums, 0, nums.size()-1);
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}