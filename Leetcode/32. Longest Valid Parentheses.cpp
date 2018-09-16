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
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		int mx = 0, l = 0;
		stack<int> st;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				st.push(i);
			}
			else {
				if (st.empty()) {
					l = i + 1;
				}
				else {
					st.pop();
					mx = st.empty() ? max(mx, i-l+1) : max(mx, i-st.top()); 
					/* 关键：先pop再取top 防止计算()()()第三对括号的时候漏掉第二对
					*/
				}
			}
		}
		return mx;
	}
};

int main(){
	Solution* s = new Solution();
	cout << s->longestValidParentheses("(()()") << endl;	 // 0
	cout << s->longestValidParentheses("(") << endl; // 0
	cout << s->longestValidParentheses(")") << endl; // 0
	cout << s->longestValidParentheses("(()") << endl;	// 2
	cout << s->longestValidParentheses("())") << endl;	// 2
	cout << s->longestValidParentheses("())())") << endl;	// 2
	cout << s->longestValidParentheses("())") << endl;	// 2
}