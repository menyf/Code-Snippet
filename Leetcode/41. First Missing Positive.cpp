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
//// header files
class Solution {
public:
	
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0) return 1;
		vector<int> a(nums.size()+2, 0);
		for (int i = 0; i < nums.size(); i++) {
			int now = nums[i];
			if (now >= 0 && now < a.size()) {
				a[now] = 1;
			}
		}
		for (int i = 1; i < a.size(); i++) {
			if (a[i] == 0) {
				return i;
			}
		}
	}
};
//// main function
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	vector<int> a;
	for (int i = -5; i < 10; i++) {
		if (i == 3) {
			continue;
		}
		else {
			a.push_back(i);
		}
	}
	cout << solution->firstMissingPositive(a) << "\n";
}