class Solution {
public:
    int romanToInt(string s) {
        reverse(s.begin(), s.end());
        unordered_map<char, int> mp;
        char sym[] = "IVXLCDM";
        int val[] = {1, 5, 10, 50, 100, 500, 1000};
        for(int i = 0; i < 7; i++){
            mp[sym[i]] = val[i];
        }
        int mx = 0, ans = 0;
        for(int i = 0; i < s.length(); i++){
            int now = mp[s[i]];
            if(now < mx) ans -= now;
            else ans += now;
            mx = max(mx, now);
        }
        return ans;
    }
};