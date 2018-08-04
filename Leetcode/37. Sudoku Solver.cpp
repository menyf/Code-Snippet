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
typedef vector<char> vc;
//// header files
class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		dfs(board, 0, 0);
	}
	
	
	bool dfs(vector<vector<char>>& mp, int x, int y) {
		if (y == 9) return dfs(mp, x+1, 0);
		if (x == 9) return true;
		if (mp[x][y] != '.') return dfs(mp, x, y+1);
		for (int i = 1; i <= 9; i++) {
			mp[x][y] = (char)(i + '0');
			if (check(mp, x, y) && dfs(mp, x, y+1)) {
				return true;
			}
			mp[i][j] = '.'; // 回溯！！
		}
		return false;
	}
	
	bool check(vector<vector<char>>& board, int x, int y) {
		for (int i = 0; i < 9 ; i++) {
			if (i != x && board[i][y] == board[x][y]) {
				return false;
			}
		}
		
		for (int i = 0; i < 9; i++) {
			if (i != y && board[x][i] == board[x][y]) {
				return false;
			}
		}
		
		
		int stx = x / 3 * 3, sty = y / 3 * 3;
		for (int i = 0; i < 9; i++) {
			int tx = stx + i % 3;
			int ty = sty + i / 3;
			if ((tx != x || ty != y) && board[tx][ty] == board[x][y]) {
				return false;
			}
		}
		
		return true;
	}
};
//// main function
int main(int argc, char *argv[]) {
	char ss[9][9] = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
	std::vector<vc> v;
	for(int i = 0; i < 9; i++){
		std::vector<char> tmp;
		for (int j = 0; j < 9; j++) {
			tmp.push_back(ss[i][j]);
		}
		v.push_back(tmp);
	}
	Solution *solution = new Solution();
	solution->solveSudoku(v);
}