#include <iostream>
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
//// header files
class Solution {
public:
	int projectionArea(vector<vector<int>>& grid) {
		// 上
		int ans = 0;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j]) ans++;
			}
		}
		
		for (int i = 0; i < grid.size(); i++) {
			int mx = 0;
			for (int j = 0; j < grid[i].size(); j++) {
				mx = max(mx, grid[i][j]);
			}
			ans += mx;
		}
		
		for (int i = 0; i < grid.size(); i++) {
			int mx = 0;
			for (int j = 0; j < grid[i].size(); j++) {
				mx = max(mx, grid[j][i]);
			}
			ans += mx;
		}
		
		return ans;
	}
};
//// main function
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}