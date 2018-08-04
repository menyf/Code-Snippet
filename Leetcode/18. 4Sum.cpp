class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		set<vector<int>> ans;
		for(int a = 0; a < nums.size(); a++){
			for(int b = a + 1; b < nums.size(); b++){
				for(int c = b+ 1; c < nums.size(); c++){
					for(int d = c + 1; d < nums.size(); d++){
						if(nums[a] + nums[b] + nums[c] + nums[d] == target){
							vector<int> v;
							v.push_back(nums[a]);
							v.push_back(nums[b]);
							v.push_back(nums[c]);
							v.push_back(nums[d]);
							sort(v.begin(), v.end());
							ans.insert(v);
						}
					}
				}
			}
		}
		return vector<vector<int>> (ans.begin(), ans.end());
	}
};