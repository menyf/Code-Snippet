#include <unordered_map>
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
class NestedInteger {
  public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
//// Answers below
typedef long long ll;
class Solution {
public:
	// descending order
	int partition(vector<int>& nums, int i, int j) {
		int pivot = nums[j - 1];
		// A[i, l - 1] < pivot
		// A[l] == pivot
		// A[l + 1, r] > pivot
		int l = i - 1;
		for (int r = i; r < j ; r++) {
			if (nums[r] >= pivot) {
				swap(nums[++l], nums[r]);
			}
		}
		return l;
	}
	
	int findKthLargest(vector<int>& nums, int k) {
		int l = 0, r = nums.size(); 
		while (true) {
			int pos = partition(nums, l, r);
			if (pos == k - 1) return nums[pos];
			else if (pos > k - 1) r = pos;
			else l = pos + 1; 
		}
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
