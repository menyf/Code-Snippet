// Wrote by MenYifan on 2016-09-15 19:18:47
// Exe.Time 0ms Exe.Memory 1568K
#include <set>
#include <map>
#include <stack>
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
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=50000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int len;
char s[1005];
int main(){
    while (scanf("%d%s",&len,s+1)!=EOF) {
        int last = -1,pre=-1;
        for (int i = 1; i<=len; i++) {
            if (s[i] == '?') {
                pre = last;
                last = i;
                s[i] = 'a';
            }
        }
        bool p = true;
        for (int i = 1; i <= len; i++) {
            if (s[i] != s[len-i+1]) {
                p = false;
                break;
            }
        }
        if (!p) {
            printf("%s\n",s+1);
        }
        else{
            if (last == -1) {
                printf("QwQ\n");
            }
            else if (len % 2 && last == (len + 1) / 2) {
                if (pre == -1) {
                    printf("QwQ\n");
                }
                else{
                    s[pre] = 'b';
                    printf("%s\n",s+1);
                }
            }
            else{
                s[last] = 'b';
                printf("%s\n",s+1);
            }
        }
    }
}