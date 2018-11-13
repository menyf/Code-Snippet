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
const double eps=1e-11;
//求无向图的割顶和桥
const int maxn=5000+10;    //顶点数
int in[maxn];
int dfs_clock;//时钟，每访问一个节点增1
vector<int> G[maxn];//G[i]表示i节点邻接的所有节点
int pre[maxn];//pre[i]表示i节点被第一次访问到的时间戳,若pre[i]==0表示i还未被访问
int low[maxn];//low[i]表示i节点及其后代能通过反向边连回的最早的祖先的pre
bool mp[maxn][maxn];
int dfs(int u,int fa=-1)//求出以u为根节点(u在DFS树中的父节点是fa)的树的所有割顶和桥
{
    int lowu=pre[u]=++dfs_clock;
    for(int i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(!pre[v]){
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
        }
        else if(pre[v]<pre[u] && v!=fa){//v!=fa确保了(u,v)是从u到v的反向边
            lowu=min(lowu,pre[v]);
        }
    }

    return low[u]=lowu;
}
void work(int n,int m){
    // input & initialize
    dfs_clock=0;//初始化时钟
    memset(pre,0,sizeof(pre));
    memset(low, 0, sizeof(low));
    memset(mp, 0, sizeof(mp));
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);//下标1~n
        if (mp[u][v]==0) {//去重
            mp[u][v] = 1;
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }
    
    //Apllication
    int k = 0;
    for (int i=1; i<=n; i++) {
        if (!pre[i]) {
            k++;
            dfs(i);//每次遍历一个连通块
        }
    }
    
    for (int i=1; i<=n; i++) {
        for (int j=0; j<G[i].size(); j++) {
            int v = G[i][j];
            if (low[i]!=low[v]) {
                in[low[v]]++;
            }
        }
    }
    int leaf = 0;
    for (int i=1; i<=n; i++) {
        if (in[i]==1) {
            leaf++;
        }
    }
    cout<<(leaf+1)/2<<"\n";
}
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        work(n, m);
    }
}
