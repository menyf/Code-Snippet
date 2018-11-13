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
const int maxn=1001+10;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int dfs_clock;//时钟
int scc_cnt;//强连通分量总数
vector<int> G[maxn];//G[i]表示i节点指向的所有点
int pre[maxn]; //时间戳
int low[maxn]; //u以及u的子孙能到达的祖先pre值
int sccno[maxn];//sccno[i]==j表示i节点属于j连通分量
stack<int> S;
void dfs(int u){
    pre[u]=low[u]=++dfs_clock;
    S.push(u);
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(!pre[v]){
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(!sccno[v]){
            low[u]=min(low[u],pre[v]);
        }
    }
    if(low[u] == pre[u]){//u为当前强连通分量的入口
        scc_cnt++;
        while(true){
            int x=S.top(); S.pop();
            sccno[x]=scc_cnt;
            if(x==u) break;
        }
    }
}

//求出有向图所有连通分量
void find_scc(int n){
    scc_cnt=dfs_clock=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
        if(!pre[i]) dfs(i);
}
int in[maxn];
vector<int>g[maxn];
void work(int n,int m){
    for(int i=0;i<=n;i++) G[i].clear();
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
    }
    find_scc(n);
    
    bool mp[maxn][maxn];
    memset(mp, false, sizeof(mp));
    memset(in, 0, sizeof(in));
    for (int i = 1; i<=scc_cnt; i++) {
        g[i].clear();
    }
    for (int u = 1; u<=n; u++) {
        for (int i = 0 ; i<G[u].size(); i++) {
            int v = G[u][i];
            int x = sccno[u], y = sccno[v];
            if (x!=y&&!mp[x][y]) {
                mp[x][y] = true;
                in[y]++;
                g[x].push_back(y);
            }
        }
    }
    
    stack<int>q;
    for (int i =1; i<=scc_cnt; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0 ;
    while (!q.empty()) {
        if (q.size() > 1)
            break;
        cnt++;
        int now = q.top(); q.pop();
        for (int i = 0 ; i<g[now].size(); i++) {
            int v = g[now][i];
            if (--in[v]==0) {
                q.push(v);
            }
        }
    }
    if (cnt == scc_cnt) {
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}
int main(){
    int n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        work(n,m);
    }
}
