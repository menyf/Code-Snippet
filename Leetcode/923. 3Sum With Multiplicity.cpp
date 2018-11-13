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
	int threeSumMulti(vector<int>& A, int target) {
		const int mod = 1000000007;
		sort(A.begin(), A.end());
		vector<int> uniq(A);
		int N = A.size();
		uniq.resize(unique(uniq.begin(), uniq.end()) - uniq.begin());
		int n = uniq.size();
		vector<int> cnt(n, 0);
		long long ans = 0;
		for (int i = 0, j = 0; i < N; i++) {
			if (A[i] == uniq[j]) 
				cnt[j]++;
			else 
				cnt[++j] = 1;
		}
		
		for (int i = 0, j, k; i < n ; i++) {
			j = cnt[i] == 1 ? i + 1 : i;
			k = n - 1;
			
			if (k == j) {
				if (j == i) {
					if (cnt[i] < 3) 
						break;
				}
				else {
					if (cnt[j] < 2) 
						break;
				}
			}
			
			while (i <= j && j <= k) {
				int sum = uniq[i] + uniq[j] + uniq[k];
				if (sum == target) {
					
					if (i != j && j != k) {
						ans = ((ans + (long long)cnt[i] * cnt[j] * cnt[k] % mod) % mod + mod ) % mod;
					}
					else if (i == j && j != k) {
						ans = ((ans + (long long)cnt[i] * (cnt[j] - 1) / 2 * cnt[k] % mod) % mod + mod ) % mod;
					}
					else if (i != j && j == k) {
						ans = ((ans + (long long)cnt[i] * cnt[j] * (cnt[k] - 1) / 2 % mod) % mod + mod ) % mod;
					}
					else {
						ans = ((ans + (long long)cnt[i] * (cnt[j] - 1) * (cnt[k] - 2) / 6 % mod) % mod + mod ) % mod;
					}
					j++, k--;
				}
				else if (sum < target) {
					j++;
				}
				else {
					k--;
				}
				if (j == k && cnt[j] < 2) {
					 break;
				}
			}
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	int a[] = {1, 1, 2, 2, 2, 2};
	int target = 5;
	vector<int> v(a, a+6);
	printf("%d\n", solution->threeSumMulti(v, target));
}
	
