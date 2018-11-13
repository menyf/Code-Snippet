// Wrote by MenYifan on 2016-08-03 23:19:42
// Exe.Time 826ms Exe.Memory 1784K
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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int main(){
    ll a, s, b;
    char str[10];
    while (~scanf("%lld",&a)) {
        scanf("%s",str);
        int len = strlen(str);
        if (len == 1 && str[0] == '0') {
            puts("0");
            continue;
        }
        ll base = 1;
        for (int i=0; i<len; i++) {
            base *= 10;
        }
//        debug(base);
        ll ans = -1;
        sscanf(str, "%lld", &s);
        for (ll i = 1 ; i <= 10000; i *= 10) {
            for (ll x = (str[0]=='0'?1:0); x<a; x++) {
                ll tmp = (x * base + s ) * i;
                ll y = (a - tmp%a) %a;
                if (y<i) {
                    tmp += y;
//                    debug(tmp);
                    if (ans == -1 || tmp < ans) {
                        ans = tmp;
                    }
                }
            }
        }
        cout<<ans/a<<endl;
    }
}