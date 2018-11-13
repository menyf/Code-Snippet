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
//点-双连通分量
const int maxn=5000+10;//点数
struct Edge{
    int u,v;
    Edge(int _u,int _v){
        u = _u, v = _v;
    }
};
int pre[maxn]; //第一次访问的dfs_clock时间戳
int low[maxn];
int vis[maxn];
int tt;
int iscut[maxn]; //割点判断
int bccno[maxn]; // bccno[i]表示i所在的点-双联通分量的下标 即bcc[bccno[i]]这个连通分量集合中含有i这个点 对于割顶来讲没有意义，因为他属于多个点-双联通分量
vector<int>belong[maxn];
int dfs_clock;
int bcc_cnt; // 双连通分量个数
vector<int>G[maxn]; // 顶点，下标0~n-1
vector<int>bcc[maxn]; //点双连通分量存储结果 下标1~bcnt
stack<Edge>S;
int dfs(int u,int fa){
    vis[u] = tt;
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for (int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        Edge e = Edge(u, v);
        if (!pre[v]) {
            S.push(e);
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);
            if (lowv >= pre[u]) {
                iscut[u] = true;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                while (true) {
                    Edge x = S.top();
                    S.pop();
                    if (bccno[x.u]!=bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u] = bcc_cnt;
                        belong[x.u].push_back(bcc_cnt);
                    }
                    if (bccno[x.v] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.v);
                        belong[x.v].push_back(bcc_cnt);
                    }
                    if (x.u == u && x.v ==v) {
                        break;
                    }
                }
            }
            
        }
        else if(pre[v] < pre[u] && v != fa){
            S.push(e);
            lowu = min(lowu, pre[v]);
        }
    }
    if (fa < 0 && child == 1) {
        iscut[u] = 0;
    }
    return  low[u]=lowu;
}
int find_bcc(int n){//n个顶点
    //栈无需清空，每次跑完必然为空
    //bcc[]无需清空，组建连通分量时已清空
    memset(pre, 0, sizeof(pre));
    memset(iscut, 0, sizeof(iscut));
    memset(bccno, 0, sizeof(bccno));
    memset(low, 0, sizeof(low));
    memset(vis, -1, sizeof(vis));
    dfs_clock = bcc_cnt = 0;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        if (!pre[i]) {
            tt = i;
            dfs(i, -1);
            cnt++;
        }
    }
    return cnt;
}

void work(int n,int m, int q){// n个点 m条边
    // input and initialize
    for (int i=0; i<n; i++) {
        G[i].clear();
        belong[i].clear();
    }
    for (int i=0; i<m; i++) {
        int u,v;
        scanf("%d%d",&u,&v);//index range: 0~n-1
        //        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    // find biconnected component
    int cnt = find_bcc(n);
    
    // output
    for (int i=0; i<q; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        if (vis[u]!=vis[v]) {
            cout<<"zero\n";
        }
        else if (bccno[u]!=bccno[v]){
            bool flag =false;
            for (int i=0; i<belong[u].size()&&!flag; i++) {
                for (int j=0; j<belong[v].size()&&!flag; j++) {
                    if (belong[u][i] == belong[v][j]) {
                        int tmp = belong[u][i];
                        if (bcc[tmp].size()>2) {
                            flag = true;
                        }
                    }
                }
            }
            if (!flag)
                cout<<"one\n";
            else
                cout<<"two or more\n";
        }
        else{
            if (bcc[bccno[u]].size()<=2)
                cout<<"one\n";
            else
                cout<<"two or more\n";
        }
    }
}
int main(){
    int n,m,q,cas=0; //n个点 m条边
    while (scanf("%d%d%d",&n,&m,&q),n) {
        printf("Case %d:\n",++cas);
        work(n, m, q);
    }
}
