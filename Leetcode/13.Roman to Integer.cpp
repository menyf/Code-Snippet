#include <iostream>
#include "string"
#include "map"
using namespace std;
class Solution {
public:
	int romanToInt(string s) {
		map<char, int> mp;
		mp['I'] = 1;
		mp['V'] = 5;
		mp['X'] = 10;
		mp['L'] = 50;
		mp['C'] = 100;
		mp['D'] = 500;
		mp['M'] = 1000;
		reverse(s.begin(), s.end());
		int mx = 1;
		int ans = 0;
		for (int i = 0; i < s.length(); i++) {
			int tmp = mp[s[i]];
			if (tmp < mx) {
				ans -= tmp;
			}
			else {
				mx = tmp;
				ans += tmp;
			}
		}
		return ans;
	}
};
int main() {
	Solution* s = new Solution();
	cout << s->romanToInt("III") << endl;
	cout << s->romanToInt("IV") << endl;
	cout << s->romanToInt("IX") << endl;
	cout << s->romanToInt("LVIII") << endl;
	cout << s->romanToInt("MCMXCIV") << endl;
}