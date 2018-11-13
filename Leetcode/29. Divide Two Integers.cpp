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
//// header files
typedef long long ll;
class Solution {
public:
	int divide(int dividend, int divisor) {

		ll a = abs((ll)dividend), b = abs((ll)divisor), ans = 0LL;
		if (divisor == 1) return dividend;
		while (a >= b) {
			ll bb = b;
			ll times = 1LL;
			while (a > bb * 2LL) {
				bb = bb * 2LL;
				times = times * 2LL;
			}
			a -= bb;
			ans += times;
		}
		if (ans > (ll)INT_MAX) {
			return INT_MAX;
		}
		else {
			return ((dividend<0)^(divisor<0) ? -ans : ans);
		}
	}
};
//// main function
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	cout<<	solution->divide(INT_MIN, -1);
	debug(INT_MIN);
}