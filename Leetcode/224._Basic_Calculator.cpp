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
  int calculate(string s) {
    if(s.empty()) return 0;
    stack<int>st;
    int sign = 1, res = 0;
    for(int i = 0; i < s.length(); i++) {
      if(s[i] == ' ') continue;
      else if('0' <= s[i] && s[i] <= '9'){
        int l = i;
        while(i < s.length() - 1&& isdigit(s[i + 1])) {
          i++;
        }
        res += sign * stoi(s.substr(l, i - l + 1));
        //printf("%d\n", res);
      }
      else if(s[i] == '+') {
        sign = 1;
      }
      else if(s[i] == '-') {
        sign = -1;
      }
      else if(s[i] == '(') {
        st.push(res);
        st.push(sign);
        res = 0;
        sign = 1;
      }
      else if(s[i] == ')') {
        res *= st.top(); st.pop();
        res += st.top(); st.pop();
      }
    }
    return res;
  }
};

//// Answers above
int main(int argc, char *argv[]) {
  Solution *solution = new Solution();
  
}
  
