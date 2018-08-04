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
	int searchInsert(vector<int>& nums, int target) {
		return nums.size() == 0 ? 0 : (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
	}
};
int main(int argc, char *argv[]) {
	
}