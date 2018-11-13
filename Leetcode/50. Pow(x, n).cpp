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
	double myPow(double x, int n) {
		int sign = 1;
		ll nn = n;
		if (nn < 0) {
			sign = -1;
			nn = -nn;
		}	
		
		double base = x;	
		double ans = 1;
		while (nn) {
			if (nn & 1) {
				ans *= base;
				debug2(base, ans);
			}
			nn >>= 1;
			base = base * base;
		}
		if (sign == -1) {
			ans = 1.0/ans;
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	solution->myPow(1.0, -2147483648);	
}