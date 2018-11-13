#include <unordered_map>
#include <unordered_set>
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
class NestedInteger {
  public:
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;

	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;

	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
//// Answers below
typedef long long ll;
class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		unordered_set<string> visited{{s}};
		vector<string>res;
		queue<string>q{{s}};
		bool found = false;
		
		while (!q.empty()) {
			string tmp = q.front(); q.pop();
			if(isValid(tmp)){
				res.push_back(tmp);
				found = true;
			}
			if(found) continue;
			for (int i = 0; i < tmp.size(); i++) {
				if(tmp[i] != '(' && tmp[i] != ')') continue;
				string ttmp = tmp.substr(0, i) + tmp.substr(i + 1);
				if(!visited.count(ttmp)) {
					visited.insert(ttmp);
					q.push(ttmp);
				}
			}
			
		}
		return res;
	}
	
	bool isValid(string s) {
		int cnt = 0;
		for(int i = 0; i < s.length(); i++) {
			if(s[i] == '(') ++cnt;
			else if (s[i] == ')' && --cnt < 0) return false;
		}
		return cnt == 0;
	}
	
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}
	
