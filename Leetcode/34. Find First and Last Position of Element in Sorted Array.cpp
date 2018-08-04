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
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans;
		ans.push_back(-1);
		ans.push_back(-1);
		if (nums.size() == 0) return ans;
		
		int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();		
		
		if (l < nums.size() && nums[l] == target) {
			ans.clear();
			ans.push_back(l);
			ans.push_back(r-1);
		}
		return ans;
	}
};
int main(int argc, char *argv[]) {
	
}