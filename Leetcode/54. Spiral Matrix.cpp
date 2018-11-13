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
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> ans;
        int r_num = matrix.size();
        if (r_num == 0)
            return ans;
        int c_num = matrix[0].size();
        if (c_num == 0)
            return ans;
        int tx[] = {0, 1, 0, -1};
        int ty[] = {1, 0, -1, 0};
        int tot = r_num * c_num;
        vector<int> vis(tot, 0);
        int x = 0, y = 0, dir = 0;
        while (tot--) {
            ans.push_back(matrix[x][y]);
            vis[x * c_num + y] = 1;
            x = x + tx[dir];
            y = y + ty[dir];
            if (x < 0 || x == r_num || y < 0 || y == c_num ||
                vis[x * c_num + y]) {
                x += tx[(dir + 1) % 4] - tx[dir],
                    y += ty[(dir + 1) % 4] - ty[dir];
                dir = (dir + 1) % 4;
            }
        }
        return ans;
    }
};
//// Answers above
int main(int argc, char *argv[]) {
    Solution *solution = new Solution();
    vector<vector<int>> v;
    vector<int> vv;
    int n = 1;
    for (int i = 1; i <= n * n; i++) {
        vv.push_back(i);
        printf("%2d ", i);
        if (i % n == 0) {
            v.push_back(vv);
            vv.clear();
            puts("");
        }
    }
    solution->spiralOrder(v);
}