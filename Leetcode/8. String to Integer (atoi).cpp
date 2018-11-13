#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        bool negative = false;

        // find st
        int st = -1;
        for(int i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ') {
                continue;
            }
            else if ((str[i] == '-' || str[i] == '+') && i + 1 != str.length() && str[i+1]>='0' && str[i+1] <= '9')
            {
                st = i+1;
                negative = str[i] == '-' ? true : false;
                break;
            }
            else if (str[i]>='0' && str[i] <= '9')
            {
               st = i;
               break;
            }
            else {
                
                return 0;
            }
        }
        
        if (st == -1) {
            return 0;
        }
        
        
        // find ed
        int ed = -1;
        for(int i = st+1; i < str.length(); i++)
        {
            if(str[i] > '9' || str[i] < '0') {
                ed = i;
                break;
            }
        }
        if (ed == -1) {
            ed = str.length();
        }
        
        // obtain number
        long long absValue = 0, ans = 0;       
        for(int i = st; i < ed; i++)
        {
            absValue = absValue * 10 + str[i] - '0';
            ans = negative? -absValue : absValue;
            
            if (ans > ((1LL << 31) - 1LL)) {
                return ((1 << 31) - 1);
            }
            else if(ans < -(1LL << 31)) {
                return -(1 << 31);
            }
            
        }
        
        // cout << st << endl;
        // cout << ed << endl;
        return (int)ans;
    }
};
int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    cout << s->myAtoi("-+1") ;
    // cout << s->myAtoi("-91283472332") ;
    return 0;
}
