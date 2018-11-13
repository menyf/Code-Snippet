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
//// Answers below
typedef long long ll;
class Solution {
public:
  int totalFruit(vector<int> &tree) {
    int a = -1, b = -1;
    int len1 = 0, len2 = 0, mx = 0;
    for (int i = 0; i < tree.size(); i++) {
      if (a == -1) {
        a = i;
        len1 = 1;
        len2 = 1;
      } else if (tree[i] == tree[a]) {
        len1++;
        if (b == -1) {
          len2++;
        } else {
          len2 = 1;
          swap(a, b);
        }
      } else if (b == -1) {
        b = i;
        len1++;
        len2 = 1;
      } else if (tree[i] == tree[b]) {
        len1++;
        len2++;
      } else {
        a = b;
        b = i;
        len1 = len2 + 1;
        len2 = 1;
      }
      mx = max(mx, len1);
    }
    return mx;
  }
};
//// Answers above
int main(int argc, char *argv[]) {
  Solution *solution = new Solution();
  int a[] = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  vector<int> v(a, a + 11);
  cout << "final ans is: ";
  cout << solution->totalFruit(v) << endl;
}