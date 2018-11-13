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
class Solution {
public:
	string countAndSay(int n) {
		string ans = "1";
		for (int i = 2; i <= n; i++) {
			string now = "";
			char ch = ans[0];
			int cnt = 1;
			for (int j = 1; j < ans.length(); j++) {
				if (ans[j] == ch) cnt++;
				else {
					now += (char)('0' + cnt);
					now += ch;
					ch = ans[j];
					cnt = 1;
				}
			}
			now += (char)('0' + cnt);
			now += ch;
			ans = now;
		}
		return ans;
	}
};
//// main function
int main(int argc, char *argv[]) {
	Solution *s = new Solution();
	for (int i = 1; i <= 10; i++) {
		cout << s->countAndSay(i) << endl;
	}
	
}