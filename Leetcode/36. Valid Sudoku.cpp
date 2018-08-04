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
	bool isValidSudoku(vector<vector<char>>& board) {
		// check row
		for (int i = 0; i < 9; i++) {
			int a[9] = {};
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.') {
					int tmp = board[i][j] - '1';
					if (a[tmp] == 0) a[tmp] = 1;
					else return false;
				}
			}
		}
		
		// check column
		for (int i = 0; i < 9; i++) {
			int a[9] = {};
			for (int j = 0; j < 9; j++) {
				if (board[j][i] != '.') {
					int tmp = board[j][i] - '1';
					if (a[tmp] == 0) a[tmp] = 1;
					else return false;
				}
			}
		}
		
		// check block
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int a[9] = {};
				for (int k = 0; k < 9; k++) {
					int x = i * 3 + k / 3;
					int y = j * 3 + k % 3;
					if (board[x][y] != '.') {
						int tmp = board[x][y] - '1';
						if (a[tmp] == 0) a[tmp] = 1;
						else return false;
					}
				}
			}
		}
		
		return true;
	}
};
//// main function
int main(int argc, char *argv[]) {
	
}