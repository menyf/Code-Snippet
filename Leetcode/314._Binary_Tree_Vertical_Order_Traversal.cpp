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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   
    vector<vector<int>> verticalOrder(TreeNode* root) {
      if(root == NULL) return {};
      map<int, vector<int>> mp;
      queue<pair<int, TreeNode*>> q{{{0, root}}};
      while(!q.empty()) {
         pair<int, TreeNode *> curr = q.front(); q.pop();
         mp[curr.first].push_back(curr.second->val);
         if(curr.second->left)
            q.push({curr.first - 1, curr.second->left});
         if(curr.second->right)
            q.push({curr.first + 1, curr.second->right});
      }
      
      vector<vector<int>> ans;
      for(auto k: mp) {
        ans.push_back(k.second);
      }
      return ans;
   }
};
int firstBadVersion(int n) {
  int left = 1;
  int right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (isBadVersion(mid)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
//// Answers above
int main(int argc, char *argv[]) {
  Solution *solution = new Solution();
  
}
  
