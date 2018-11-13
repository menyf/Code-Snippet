class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> v(numRows, "");
        int r = 0;
        bool dir = true; //down
        for(int i = 0; i < s.length(); i++){
            v[r] += s[i];
            if(r == numRows-1) dir = false;
            if(r == 0) dir = true;
            if(dir) r = r + 1;
            else r = r - 1;
        }
        string ans;
        for(int i = 0; i < numRows; i++){
            ans += v[i];
        }
        return ans;
    }
    
};
