class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int vis[300] = {};
        memset(vis, -1, sizeof(vis));
        int st = 0;
        int mx = 0;
        for(int i = 0; i < s.length(); i++){
            int ch = s[i];
            if(vis[ch] != -1) st = max(st, vis[ch] + 1);
            vis[ch] = i;
            mx = max(mx, i - st + 1);
        }        
        return mx;
    }
};