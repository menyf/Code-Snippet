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
  void rotate(vector<vector<int> > &matrix) {
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; i++) {
      for (int j = 0; j < (n + 0) / 2; j++) {
        int x = i, y = j;
        int prev = matrix[x][y];
        for (int k = 0; k < 4; k++) {
          swap(prev, matrix[y][n - 1 - x]);
          int tmp = x;
          x = y;
          y = n - 1 - tmp; 
        }
        
      }
    }
  }
};
//// Answers above
int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    vector<vector<int> > v;
    vector<int> tmp;
    for(int i = 1; i <= 9; i++){
        tmp.push_back(i);
        if(i && i%3 == 0){
            v.push_back(tmp);
            tmp.clear();
        }
    }
    solution->rotate(v);
    int n =3;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d%c",v[i][j], j == n-1?'\n':' ');
      }
    }
    return 0;
}