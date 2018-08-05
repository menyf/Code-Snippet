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
	string decodeAtIndex(string S, int K) {
		if (!isdigit(S[(int)S.length() - 1])) S += '1';
		string ans = "";
		int idx[100] = {-1}, n = 0;
		for (int i = 0; i < S.length(); i++) 
			if (isdigit(S[i])) idx[++n] = i;
		unsigned long long len[100] = {};
		for (int i = 1 ; i <= n ; i++) {
			len[i] = (len[i-1] + idx[i] - idx[i-1] - 1) * (S[idx[i]] - '0'); 
		}
		int k = K;
		for (int i = n; i >= 1; i--) {
			int times = S[idx[i]] - '0';
			unsigned long long a = len[i-1]; // 前一个字符串长度
			unsigned long long c = len[i] / times; //不加倍的
			unsigned long long pos = (k % c == 0 ? c : k % c);
			if (pos > a) return ans + S[idx[i-1]+pos-a];
			else k = pos;
		}
	
		return "";
	}
};
//// main function
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
//	cout<< solution->decodeAtIndex("leet2code3", 4) <<endl;
	for (int i = 1; i <= 1 ; i++) {
		cout<< solution->decodeAtIndex("a2345678999999999999999", i) ;
	}
	
}