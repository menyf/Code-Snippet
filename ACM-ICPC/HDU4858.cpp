// Wrote by MenYifan on 2016-03-07 19:01:49
// Exe.Time 780ms Exe.Memory 8612K
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#define PI acos(-1)
#define rt(n)       (i==n?'\n':' ')
#define debug         printf("Hi----------\n")
#define eps 1e-8
#define INF 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
#define maxn 10005
vector<ll>g[100005];
ll e[100005];
int u,v,n,m;
inline void scan(int &x)
{
    char c; for(c = getchar();c < '0' || c > '9';c = getchar());    x = c - '0';
    for(c = getchar();c >= '0' && c <= '9';c = getchar())   x = (x << 1) + (x << 3) + c - '0';
}
void init(){
    for (int i=0; i<=n; i++) {
        g[i].clear();
        e[i]=0;
    }
}
int main(){
    int T,c;
    scanf("%d",&T);
    while (T--) {
        ll ans=0;
        scanf("%d%d",&n,&m);
        init();
        while (m--) {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        
        scan(m);
        while (m--) {
            scan(c);
            if (c==0) {
                scan(u),scan(v);
                e[u]+=v;
            }
            else{
                ans=0;
                scan(u);
                int sz=g[u].size();
                for (int i=0; i<sz; i++) {
                    ans+= e[g[u][i]];
                }
                printf("%lld\n",ans);
            }
                
        }
    }
}