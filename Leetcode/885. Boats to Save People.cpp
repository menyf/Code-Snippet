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
	int numRescueBoats(vector<int>& people, int limit) {
		sort(people.begin(), people.end());
		int p1 = 0, p2 = people.size() - 1;
		int ans = 0;
		while (p1 <= p2) {
			int w1 = people[p1];
			int w2 = people[p2];
			if (w2 + w1 > limit) {
				p2--;
			}
			else {
				p1++,p2--;
			}
			ans++;
		}
		return ans;
	}
};
//// main function
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}