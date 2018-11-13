#include <unordered_map>
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
	vector<string> ss = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};		
	vector<string> s = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
public:
	string helper(int num){
		if (num >= 1000000000) {
			if (num % 1000000000 == 0) {
				return numberToWords(num / 1000000000) + " Billion";
			}
			else {
				return numberToWords(num / 1000000000) + " Billion " + numberToWords(num % 1000000000);
			}
		}
		else if (num >= 1000000) {
			if (num % 1000000 == 0) {
				return numberToWords(num / 1000000) + " Million";
			}
			else {
				return numberToWords(num / 1000000) + " Million " + numberToWords(num % 1000000);
			}
		}
		else if (num >= 1000) {
			if (num % 1000 == 0) {
				return numberToWords(num / 1000) + " Thousand";
			}
			else {
				return numberToWords(num / 1000) + " Thousand " + numberToWords(num % 1000);
			}
		}
		else if (num >= 100) {
			if (num % 100 == 0) {
				return numberToWords(num / 100) + " Hundred";
			}
			else {
				return numberToWords(num / 100) + " Hundred " + numberToWords(num % 100);
			}
		}
		else if (num && num % 10 == 0) {
			return ss[num / 10];
		}
		else if (num > 20) {
			return ss[num / 10] + " " + numberToWords(num % 10);
		}
		else {
			return s[num];
		}	
	}
	
	string numberToWords(int num) {
		return !num ? "Zero" : helper(num);
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	int n;
	while (cin>>n) {
		debug(solution->numberToWords(n));
	}
	
	
}
	
