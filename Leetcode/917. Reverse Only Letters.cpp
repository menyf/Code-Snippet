class Solution {
public:
	string reverseOnlyLetters(string S) {
		int l = -1, r = S.length();
		while (true) {
			while (!isalpha(S[++l]));
			while (!isalpha(S[--r]));
			if (l >= r) break;
			swap(S[l], S[r]);
		}
		return S;
	}
};