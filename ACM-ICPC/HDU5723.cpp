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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef long long ll;
using namespace std;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
typedef long long mytype;
#define Vmax 100005
#define Emax 1000005;
struct Edge{
    int v,next;
    int length;
}e[2*1000005];
ll weight;
int he[Vmax],ecnt,n,m;
int dis[Vmax],vis[Vmax],pre[Vmax],son[Vmax];
void adde(int u ,int v, int w){
    e[ecnt].v=v;
    e[ecnt].length=w;
    e[ecnt].next=he[u];
    he[u]=ecnt++;
}
void init(){
    Memset(he, -1);
    Memset(dis, INF);
    Memset(vis, 0);
    Memset(son, 1);
    ecnt=0;
    weight=0;
    scanf("%d%d",&n,&m);
}

struct point
{
    int u;
    mytype l;
    point(int u,mytype l):u(u),l(l) {}
    bool operator<(const point &p) const
    {
        return l>p.l;
    }
};
void prim_heap(int s=1)
{
    priority_queue<point> q;
    q.push(point(s,0));
    weight=0;
    dis[1]=0;
    while(!q.empty())
    {
        point p=q.top();
        q.pop();
        int u=p.u;
        if (vis[u])
            continue;
        vis[u]=1;
        weight+=p.l;//==dis[x]
        for (int i=he[u]; i!=-1; i=e[i].next)
            if (!vis[e[i].v]&&e[i].length<dis[e[i].v])
            {
                dis[e[i].v]=e[i].length;
                pre[e[i].v]=u;
                q.push(point(e[i].v,dis[e[i].v]));
            }
    }

}
void prep(){
    Memset(he, -1);
    ecnt=0;
    for (int i=2; i<=n; i++) {
        adde(pre[i], i, dis[i]);
    }
}
void dfs(int x){
    son[x]=1;
    for (int i = he[x]; i!=-1; i=e[i].next) {
        int v = e[i].v;
        dfs(v);
        son[x]+=son[v];
    }
    return;
}
int main(){
    int t,x,y,l;
    scanf("%d",&t);
    while (t--) {
        init();
        for (int i=1; i<=m; i++) {
            scanf("%d%d%d",&x,&y,&l);
            adde(x, y, l);
            adde(y, x, l);
        }
        prim_heap();
        prep();
        dfs(1);
        ll tmp = 0;
        for (int i=0; i<ecnt; i++) {
            int v = e[i].v;
            ll len = e[i].length;
            tmp+=len*son[v]*(n-son[v]);
        }
        double ans=1.0*tmp*2/(1.0*n*(n-1));
        printf("%lld %.2f\n",weight,ans);
    }
    return 0;
}
