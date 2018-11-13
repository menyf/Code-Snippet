/*
思路：参考马拉车算法，相邻两个字符之间先插入一个字符
*/

class Solution
{
  public:
    string longestPalindrome(string s)
    {

        int tmp[2010];
        for (int i = 0; i < s.length(); i++)
        {
            tmp[2 * i] = -1;
            tmp[2 * i + 1] = s[i];
        }
        tmp[2 * s.length()] = -1;

        int len = 2 * s.length() + 1;

        int mx = 0, st = 0;
        for (int c = 1; c < len; c++)
        {
            for (int i = 0; c + i < len && c - i >= 0; i++)
            {
                if (tmp[c + i] != tmp[c - i])
                    break;
                if (mx < i)
                {
                    mx = i;
                    st = (c - i) / 2;
                }
            }
        }
        return s.substr(st, mx);
    }
};