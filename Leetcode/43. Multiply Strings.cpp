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
	
	void dfs(string &num, int flag, int pos) {
		int val = num[pos] - '0';
		if (flag + val < 10) {
			num[pos] += flag;
		}
		else {
			num[pos] = (val + flag) % 10 + '0';
			dfs(num, (val+flag)/10, pos+1);
		}
	}
	
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string ans;
		for (int i = 0; i < 110*110; i++) {
			ans += "0";
		}
		for (int i = 0; i < num1.length(); i++) {
			int a = num1[i] - '0';
			int flag = 0;
			for (int j = 0; j < num2.length(); j++) {
				int b = num2[j] - '0'; 
				int rslt = a * b + flag + ans[i+j] - '0';
				ans[i+j] = rslt % 10 + '0';
				flag = rslt / 10;
			}
			dfs(ans, flag, i+num2.length());
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < ans.length(); i++) {
			if (ans[i] != '0') {
				return &ans[i];
			}
		}
		return "0";
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	debug(solution->multiply("2", "111"));
}