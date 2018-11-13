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
	struct Node{
		string s;
		string ordered;
		bool operator < (const Node rhs) const{
			return ordered < rhs.ordered;
		}
	};

	typedef struct Node node;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		vector<node>v(strs.size());
		for (int i = 0; i < strs.size(); i++) {
			v[i].s = strs[i];
			sort(strs[i].begin(), strs[i].end());
			v[i].ordered = strs[i];
		}
		sort(v.begin(), v.end());
		vector<string> v_str;
		v_str.push_back(v[0].s);
		for (int i = 1; i < v.size(); i++) {
			if (v[i].ordered == v[i-1].ordered) {
				v_str.push_back(v[i].s);
			}
			else {
				ans.push_back(v_str);
				v_str.clear();
				v_str.push_back(v[i].s);
			}
		}
		ans.push_back(v_str);
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}