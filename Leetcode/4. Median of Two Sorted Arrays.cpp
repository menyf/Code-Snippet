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
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size() + nums2.size();
		if (n % 2 == 1) return findKth(nums1, 0, nums2, 0, n / 2 + 1);
		else return 0.5 * (findKth(nums1, 0, nums2, 0, n / 2) + findKth(nums1, 0, nums2, 0, n / 2 + 1));
	}
	
	double findKth(vector<int>& nums1, int idx1, vector<int>& nums2, int idx2, int k) {
		if (nums1.size() - idx1 > nums2.size() - idx2) return findKth(nums2, idx2, nums1, idx1, k);
		if (nums1.size() == idx1) return nums2[idx2 + k - 1];
		if (k == 1) return min(nums1[idx1], nums2[idx2]);
		int pa = min(idx1 + k / 2, (int)nums1.size()), pb = idx2 + (k - (pa - idx1));
		if (nums1[pa - 1] > nums2[pb - 1]) 
			return findKth(nums1, idx1, nums2, pb, k - (pb - idx2));
		else if (nums1[pa - 1] < nums2[pb - 1]) 
			return findKth(nums1, pa, nums2, idx2, k - (pa - idx1));
		else {
			return nums1[pa - 1]
		}
	}
};
int main(int argc, char *argv[]) {
	
}