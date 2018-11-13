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
#include <unordered_set>
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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    if (matrix.empty() || matrix[0].empty())
      return false;
    int n = matrix.size(), m = matrix[0].size();

    for (int i = 0; i < n; i++) {
      if (matrix[i].front() > target || matrix[i].back() < target)
        continue;
      int l = 0, r = m;
      while (l < r) {
        int mid = (l + r) / 2;
        if (matrix[i][mid] < target) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      if (matrix[i][l] == target)
        return true;
    }

    return false;
  }
};

//// Answers above
int main(int argc, char *argv[]) { Solution *solution = new Solution(); }
