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
//// Answers below
typedef long long ll;
class Solution {
public:
	int sumSubarrayMins(vector<int>& A) {
		long long ans = 0;
		const int mod = 1000000007;
		vector<int> vis(A.size(), -1);
		for (int i = 0; i < A.size(); i++) {
			int r = i;
			while (++r < A.size() && A[i] < A[r]){
				vis[r] = i;
			}
			ans = (ans + (long long)(i-vis[i])*(r-i)*A[i] % mod) % mod;
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}