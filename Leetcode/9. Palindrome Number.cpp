//坑：负数一律不是回文数
class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 ) return false;
        int digt[50], len=0;
        while(x){
            digt[len++] = x%10;
            x /= 10;
        }
        int st = 0, ed = len - 1;
        while(st < ed){
            if(digt[st] != digt[ed]) return false;
            st++, ed--;
        }
        return true;
    }
};