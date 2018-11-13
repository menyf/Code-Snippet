class Solution {
public:
    int reverse(int x) {
        long long rt = 0;
        while(x){
            rt = rt*10 + x%10;
            x /= 10;
        }
        if(rt > INT_MAX || rt < INT_MIN ) rt = 0;
        return rt;
    }
};