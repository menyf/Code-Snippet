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
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> ans;
    ans.insert(nums);
    bool flag = true;
    while (flag) {
      flag = false;
      for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
          for (int j = n - 1; j > i; j--) {
            if (nums[i] < nums[j]) {
              flag = true;
              swap(nums[i], nums[j]);
              reverse(nums.begin() + i + 1, nums.end());
              ans.insert(nums);
              break;
            }
          }
          break;
        }
      }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
  }
};
//// Answers above
int main(int argc, char *argv[]) { Solution *solution = new Solution(); }