class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int n = nums.size();
		int diff = INT_MAX;
		int ans = -1;
		for (int i = 0; i < n ; i++) {
			for (int j = i + 1; j < n ; j++) {
				for (int k = j + 1; k < n; k++) {
					int now = nums[i] + nums[j] + nums[k];
					int dis = abs(now - target);
					if (dis < diff) {
						ans = now;
						diff = dis;
					}
				}
			}
		}
		return ans;
	}
};