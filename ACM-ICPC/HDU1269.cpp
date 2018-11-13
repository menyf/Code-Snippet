// Wrote by MenYifan on 2016-09-17 21:13:21
// Exe.Time 78ms Exe.Memory 3820K
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
const int maxn=10000+10;
int dfs_clock;//??
int scc_cnt;//???????
vector<int> G[maxn];//G[i]??i????????
int pre[maxn]; //???
int low[maxn]; //u??u?????????pre?
int sccno[maxn];//sccno[i]==j??i????j???? sccno[i]????1~scc_cnt
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
    if(low[u] == pre[u]){//u???????????
        scc_cnt++;
        while(true){
            int x=S.top(); S.pop();
            sccno[x]=scc_cnt;
            if(x==u) break;
        }
    }
}
//???????????
void find_scc(int n){
    scc_cnt=dfs_clock=0;
    memset(sccno,0,sizeof(sccno));
    memset(pre,0,sizeof(pre));
    for(int i=1;i<=n;i++)
        if(!pre[i]) dfs(i);
}
void work(int n,int m){
    for(int i=1;i<=n;i++) G[i].clear();
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);//index range: 1~n
        G[u].push_back(v);
    }
    find_scc(n);
    if (scc_cnt == 1)
        puts("Yes");
    else
        puts("No");
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n){
        work(n,m);
    }
}