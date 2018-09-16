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
	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> ans;
		for(int i = 0; i < A.size(); i++){
			if(A[i] % 2 ==0) ans.push_back(A[i]);
		}
		for(int i = 0; i < A.size(); i++){
			if(A[i] % 2 ==1) ans.push_back(A[i]);
		}
		return ans;
	}
};
//// Answers above
int main(int argc, char *argv[]) {
	Solution *solution = new Solution();
	
}