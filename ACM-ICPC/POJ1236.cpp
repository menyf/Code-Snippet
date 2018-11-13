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
const int maxn=100+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int dfs_clock;//时钟
int scc_cnt;//强连通分量总数
vector<int> G[maxn];//G[i]表示i节点指向的所有点
int pre[maxn]; //时间戳
int low[maxn]; //u以及u的子孙能到达的祖先pre值
int sccno[maxn];//sccno[i]==j表示i节点属于j连通分量
int in[maxn],out[maxn];
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
    for(int i=0;i<n;i++)
        if(!pre[i]) dfs(i);
}
void work(int n){
    for(int i=0;i<n;i++) G[i].clear();
    for (int u = 0; u<n; u++) {
        int tmp;
        while (scanf("%d",&tmp),tmp) {
            G[u].push_back(tmp-1);
        }
    }
    find_scc(n);
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for (int u = 0; u < n; u++) {
        for (int j = 0; j < G[u].size(); j++) {
            int v = G[u][j];
            if (sccno[u]!=sccno[v]) {
                in[sccno[v]]++;
                out[sccno[u]]++;
            }
        }
    }
    int a = 0, b = 0;
    for (int i=1; i<=scc_cnt; i++) {
        if (in[i]==0) {
            a++;
        }
        if (out[i]==0) {
            b++;
        }
    }
    int ans1 = max(a, b);
    if (scc_cnt == 1) {
        ans1 = 0;
    }
    cout<<a<<"\n"<<ans1<<"\n";
}
int main(){
    int n,m;
    while(scanf("%d",&n)!=EOF){
        work(n);
    }
}
