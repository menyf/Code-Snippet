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
  
  int dis = 30000;
  vector<char>dict;
  string ans;
  int now;
  
  bool isValid(string &s){
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(2));
    return hh < 24 && mm < 60;
  }
  
  void dfs(string s){
    if(s.length() == 4) {
      if(!isValid(s)) return;
      int hh = stoi(s.substr(0, 2));
      int mm = stoi(s.substr(2));
      int t = hh * 60 + mm;
      if(t <= now)  t += 1440;
      if(dis > t - now ) {
        dis = t - now;
        ans = s;
      }
      return;
    }
    for(int i = 0; i < 4; i++) {
      dfs(s + dict[i]);
    }
    return;
  }
  
  string nextClosestTime(string time) {
    dict = {time[0], time[1], time[3], time[4]};
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3));
    now = hh * 60 + mm;
    dfs("");
    return ans.substr(0, 2) + ":" + ans.substr(2);  
  }
};
//// Answers above
int main(int argc, char *argv[]) {
  Solution *solution = new Solution();
  
}
  
