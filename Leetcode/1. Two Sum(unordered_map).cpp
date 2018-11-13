#include <iostream>
#include "unordered_map"
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int>mp;
		vector<int>v;
		for (int i = 0; i < nums.size(); i++) {
			mp[nums[i]] = i;
		}
		
		for (int i = 0; i < nums.size(); i++) {
			if (mp.find(target - nums[i]) != mp.end()) {
				v.push_back(i);
				v.push_back(mp[target - nums[i]]);
				break;
			}
		}
		return v;
		
	}
};
int main(int argc, char *argv[]) {
	
}