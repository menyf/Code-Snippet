class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (digits.length() == 0) return ans;
		int cnt[] = {0, 3, 6, 9, 12, 15, 19, 22, 26};
		ans.push_back("");
		for(int i = 0; i < digits.length(); i++){
			int val = digits[i] - '2';
			vector<string> tmp;
			int n = ans.size();
			for(int j = 0; j < n; j++){
				string str = ans[j];
				for(int k = cnt[val]; k < cnt[val+1]; k++){
					char ch = 'a' + k;
					tmp.push_back(str + ch);
				}
			}
			ans.swap(tmp);
		}
		return ans;		
	}
};