#include "cstdio"
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:

	int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size()-1, n = nums.size();
		
		while (l <= r) {
			int mid = (l+r)/2;
			if (nums[mid] == target) {
				return mid;
			}	
			else if (nums[mid] < nums[r]) { // right interval
				if (target > nums[mid] && target <= nums[r]) {
					l = mid + 1;
				}
				else {
					r = mid - 1;
				}
			}
			else {
				if (target >= nums[l] && target < nums[mid]) {
					r = mid - 1;
				}
				else {
					l = mid + 1;
				}
			}
		}		

		return -1;
	}

};

int main() {
	Solution *s = new Solution();
	int a[] = {3, 4, 5, 0, 1, 2};
	int b[] = {1, 2, 3, 4, 5, 6};
	vector<int> v(a, a+6);
	
//	cout << s->binary_search(b, 0, 6, 0) << endl;
//	cout << s->binary_search(b, 0, 6, 1) << endl;
//	cout << s->binary_search(b, 0, 6, 2) << endl;
//	cout << s->binary_search(b, 0, 6, 3) << endl;
//	cout << s->binary_search(b, 0, 6, 4) << endl;
//	cout << s->binary_search(b, 0, 6, 5) << endl;
//	cout << s->binary_search(b, 0, 6, 6) << endl;
	
	cout << s->search(v, 3) << endl;
	cout << s->search(v, 4) << endl;
	cout << s->search(v, 5) << endl;
	cout << s->search(v, 0) << endl;
	cout << s->search(v, 1) << endl;
	cout << s->search(v, 2) << endl;
}