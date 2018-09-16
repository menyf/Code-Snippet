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
	bool nextPermutation(vector<int>& nums) {
		int n = nums.size();
		for (int i = n - 2; i>=0; i--) {
			if (nums[i] < nums[i+1]) {
				for (int j = n-1; j >= i+1; j--) {
					if (nums[j] >nums[i]) {
						swap(nums[i], nums[j]);
						reverse(nums.begin()+i+1, nums.end());
						return true;
					}
				}
			}
		}
		reverse(nums.begin(), nums.end());
		return false;
	}
	
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		ans.push_back(nums);
		while (next_permutation(nums.begin(), nums.end())) {
			ans.push_back(nums);
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}