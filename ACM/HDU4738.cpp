//HDU 4738
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
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int maxn=1000+10;
int n,m,ans;
int dfs_clock;
vector<int> G[maxn];
int pre[maxn],low[maxn];
int mp[maxn][maxn];
int dfs(int u,int fa = -1){
    int lowu = pre[u] = ++dfs_clock;
    for (int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        if (!pre[v]) {
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv > pre[u]) {//Bridge
                ans = min(ans, mp[u][v]);
            }
        }
        else if (pre[v] < pre[u] && v!=fa)
            lowu = min(lowu, pre[v]);
    }
    return low[u] = lowu;
}
int main(){
    while (scanf("%d%d",&n,&m)!=EOF) {
        if (n==0) break;
        memset(mp, INF, sizeof(mp));
        memset(pre, 0, sizeof(pre));
        memset(low, 0, sizeof(low));
        ans = INF;
        for (int i=1; i<=n; i++) G[i].clear();
        while (m--) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if (mp[u][v]==INF) {
                G[u].push_back(v);
                G[v].push_back(u);
                mp[u][v] = mp[v][u] = w;
            }
            else{
                mp[u][v] = mp[v][u] = INF;
            }

        }
        dfs(1);
        bool flag = false;
        for (int i=1; i<=n; i++) {
            if (pre[i] == 0) {//没有连通上所有点
                flag = true;
                break;
            }
        }
        
        if (flag)
            cout<<0<<"\n"; //本身就不联通
        else if (ans == INF)
            cout<<"-1\n"; //没有桥
        else if(ans == 0)
            cout<<"1\n"; //有桥且桥上没人 派一个兵去炸
        else
            cout<<ans<<"\n"; //有桥有人，拼人头
    }
}
