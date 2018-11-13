#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iosfwd>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#define debug(x) cout << "Debug : ---" << x << "---" << endl;
#define debug2(x, y) cout << "Debug : ---" << x << " , " << y << "---" << endl;
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
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
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
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> v(26, 0);
    for (int i = 0; i < tasks.size(); i++) {
      int ch = tasks[i] - 'A';
      v[ch]++;
    }
    int mx = 0, mxCnt = 0;
    for (int i = 0; i < 26; i++) {
      if (v[i] > mx) {
        mx = v[i];
        mxCnt = 1;
      } else if (v[i] == mx) {
        mxCnt++;
      }
    }
    int row_num = mx - 1;
    int col_num = n - (mxCnt - 1);
    int task_num = tasks.size() - mxCnt * mx;
    int idle = max(0, row_num * col_num - task_num);
    return tasks.size() + idle;
  }
};
//// Answers above
int main(int argc, char *argv[]) {
  Solution *solution = new Solution();

  vector<vector<int>> vv(10);
  for (int i = 0; i < 10; i++) {
    vector<int> v(10, 0);
    vv[i](10);
  }
}
