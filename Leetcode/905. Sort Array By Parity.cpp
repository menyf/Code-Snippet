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
  vector<int> sortArrayByParity(vector<int> &A) {
    vector<int> ans;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] % 2 == 0)
        ans.push_back(A[i]);
    }
    for (int i = 0; i < A.size(); i++) {
      if (A[i] % 2 == 1)
        ans.push_back(A[i]);
    }
    return ans;
  }
};
//// Answers above
int main(int argc, char *argv[]) { Solution *solution = new Solution(); }