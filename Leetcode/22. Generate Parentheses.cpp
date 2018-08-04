class Solution {
public:
	
	vector<string> ans;
	int len;
	
	// cnt: how many '(' left in the string not matched
	// tot: how many '(' in sum
	void dfs(string s, int cnt, int tot = 1) {
		if (s.length() == len) {
			ans.push_back(s);
			return;
		}
		
		if (tot + 1 <= (len + 1) / 2) {
			dfs(s+'(', cnt+1, tot+1);
		}
		
		if (cnt - 1 >= 0) {
			dfs(s+')', cnt-1, tot);
		}
	}
	
	vector<string> generateParenthesis(int n) {
		len = n * 2;
		dfs("(", 1, 1);
		return ans;
	}
};