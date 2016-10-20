// Wrote by MenYifan on 2016-09-02 20:17:55
// Exe.Time 265ms Exe.Memory 1576K
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <bitset>
#include <cstring>
#include <iostream>
#include <iosfwd>
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1.0)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
char num[205];
char tmp[205];
int toInt(char s){
    if ('0'<=s&&s<='9') {
        return s-'0';
    }
    else if('a'<=s&&s<='z'){
        return s-'a'+10;
    }
    else
        return 0;
}
char toChar(int a){
    if (a<10) {
        return a+'0';
    }
    else{
        return a-10+'a';
    }
}
int main(){
    int n,B;
    while (scanf("%d%d",&n,&B)!=EOF) {
        Memset(num, 0);
        scanf("%s",num);
        int len =strlen(num);
        reverse(num, num+len);
        for (int i=2; i<=n; i++) {
            Memset(tmp, 0);
            scanf("%s",tmp);
            int LEN = strlen(tmp);
            reverse(tmp, tmp+LEN);
            len = max(len, LEN);
            for (int j=0; j<len; j++) {
                int a = toInt(num[j]) + toInt(tmp[j]);
                a = a % B;
                num[j] = toChar(a);
            }
        }
        bool flag = true;
        for (int i=len-1; i>=0; i--) {
            if (num[i]!='0') {
                flag = false;
            }
            if (!flag) {
                printf("%c",num[i]);
            }
        }
        if (flag) {
            printf("0");
        }
        puts("");
    }
}