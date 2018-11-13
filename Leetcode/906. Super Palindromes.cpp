#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define debug(x) cout << "Debug : ---" << x << "---" << endl;
#define debug2(x, y) cout << "Debug : ---" << x << " , " << y << "---" << endl;
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
	bool isPalin(ll num) {
		string s = to_string(num);
		int l = 0, r = s.length() - 1;
		while (l < r) {
			if (s[l++] != s[r--])
				return false;
		}
		return true;
	}
	int superpalindromesInRange(string L, string R) {
		ll l = stoll(L);
		ll r = stoll(R);
		int cnt = 0;
		for (int i = 1; i < 1e5; i++) {
			string a = to_string(i);
			string b = a;
			reverse(b.begin(), b.end());
			string c = a + b;
			ll d = stoll(c);
			if (d * d >= l && d * d <= r && isPalin(d * d))
				cnt++;
			c = a + b.substr(1);
			d = stoll(c);
			if (d * d >= l && d * d <= r && isPalin(d * d))
				cnt++;
		}
		return cnt;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	return 0;
}