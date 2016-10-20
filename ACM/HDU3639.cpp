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
const int maxn = 5000+10;
int dfs_clock;
int scc_cnt;
vector<int> G[maxn],mp[maxn],belong[maxn];
int pre[maxn];
int low[maxn];
int sccno[maxn];
stack<int>S;
void dfs(int u){
    pre[u] = low[u] = ++dfs_clock;
    S.push(u);
    for (int i = 0; i<G[u].size(); i++) {
        int v = G[u][i];
        if (!pre[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!sccno[v]){
            low[u] = min(low[u], pre[v]);
        }
    }
    if (low[u] == pre[u]) {
        scc_cnt++;
        belong[scc_cnt].clear();
        while (true) {
            int x = S.top(); S.pop();
            sccno[x] = scc_cnt;
            belong[scc_cnt].push_back(x);
            if (x == u) {
                break;
            }
        }
    }
}
void find_scc(int n){
    scc_cnt = dfs_clock = 0;
    memset(sccno, 0, sizeof(sccno));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i<=n; i++) {
        if (!pre[i]) {
            dfs(i);
        }
    }
}
bool out[maxn],vis[maxn];
int dfs2(int now){ //对缩点后的DAG的图的反图进行DFS
    vis[now] = true;
    int ret = belong[now].size();
    for (int i = 0; i < mp[now].size(); i++) {
        int v = mp[now][i];
        if (!vis[v]) {
            ret += dfs2(v);
        }
    }
    return ret;
}
void work(int n, int m ){
    for (int i =1; i<=n; i++) {
        G[i].clear();
    }
    while (m--) {
        int u,v;
        scanf("%d%d",&u,&v);
        u++, v++;
        G[u].push_back(v);
    }
    find_scc(n);
    
    // 缩点后的DAG的图的反图
    for (int i = 1; i<=scc_cnt; i++)
        mp[i].clear();
    memset(out, false, sizeof(out));
    for (int u = 1; u<= n; u++) {
        for (int i = 0 ; i<G[u].size(); i++) {
            int v = G[u][i];
            int x = sccno[u];
            int y = sccno[v];
            if (x != y) {
                mp[y].push_back(x);
                out[x] = true;
            }
        }
    }
    
    vector<int> st;
    int mx = -1;
    for (int i = 1; i<=scc_cnt; i++) {
        if (!out[i]) {
            memset(vis, false, sizeof(vis));
            int tmp = dfs2(i);
            if (tmp > mx) { //找到票数更多的人
                st.clear();
                st.push_back(i); //下标为i的强连通分量更优
                mx = tmp;
            }
            else if (tmp==mx){  //下标为i的强连通分量符合条件
                st.push_back(i);
            }
        }
    }
    
    printf("%d\n",mx - 1); //去除自己给自己的票
    vector<int> ans;
    for (auto i : st)
        for (auto j : belong[i])
            ans.push_back(j);
    sort(ans.begin(), ans.end()); //将点排序
    
    // Output
    bool first = true;
    for (int i = 0; i<ans.size(); i++) {
        if (first) {
            printf("%d",ans[i]-1);
            first = false;
        }
        else
            printf(" %d",ans[i]-1);
    }
    printf("\n");
}
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        scanf("%d%d",&n,&m);
        printf("Case %d: ",cas++);
        work(n, m);
    }
    return 0;
}
