#include "string"
#include "stack"
#include "iostream"
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.length(); i++) {
			char now = s[i];
			char top = st.empty()? ' ' : st.top();
			if (now == '(' || now == '[' || now == '{') {
				st.push(now); continue;
			}
			else if (now == ')' && top == '(') {
				st.pop(); continue;
			}
			else if (now == ']' && top == '[') {
				st.pop(); continue;
			}
			else if (now == '}' && top == '{') {
				st.pop(); continue;
			}
			else {
				return false;
			}
		}
		return st.empty();
	}
};
int main() {
	Solution* s = new Solution();
	cout << s->isValid("()") << endl;
	cout << s->isValid("()[]{}") << endl;
	cout << s->isValid("(]") << endl;
	cout << s->isValid("([)]") << endl;
	cout << s->isValid("{[]}") << endl;
}