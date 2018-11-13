// Wrote by MenYifan on 2016-09-01 18:52:07
// Exe.Time 3650ms Exe.Memory 19972K
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
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#define debug2(x,y) cout<<"Debug : ---"<<x<<" , "<<y<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=30+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
// ?? ????????
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int Vmax = 1*1e5 + 5;//????
const int Emax = 2*1e5 + 5;//???? ??Vmax???
namespace poufen{
    int siz[Vmax],son[Vmax],fa[Vmax],dep[Vmax],top[Vmax],w[Vmax];
    int sum1[Vmax],sum2[Vmax];
    int nodenum;
    
    struct edge{
        int v,next;
    }e[Emax];
    int pre[Vmax],ecnt;
    inline void init(){
        memset(pre, -1, sizeof(pre));
        ecnt=0;
    }
    inline void add_(int u,int v){
        e[ecnt].v=v;
        e[ecnt].next=pre[u];
        pre[u]=ecnt++;
    }
    void update1(int u,int v,int c){
        sum1[u] += c;
        sum1[v+1] -= c;
    }
    void update2(int u,int v,int c){
        sum2[u] += c;
        sum2[v+1] -= c;
    }
    void dfs(int u){
        siz[u]=1;son[u]=0;//???1???son[0]???0
        for(int i=pre[u];~i;i=e[i].next)
        {
            int v=e[i].v;
            if(fa[u]!=v)
            {
                fa[v]=u;
                dep[v]=dep[u]+1;//?????dep!!
                dfs(v);
                siz[u]+=siz[v];
                if(siz[v]>siz[son[u]])son[u]=v;
            }
        }
    }
    void build_tree(int u,int tp){
        top[u]=tp,w[u]=++nodenum;
        if(son[u])build_tree(son[u],tp);
        for(int i=pre[u];~i;i=e[i].next)
            if(e[i].v!=fa[u]&&e[i].v!=son[u])
                build_tree(e[i].v,e[i].v);
    }
    
    inline void upd1(int u,int v,int c){ //???+=c,?
        int f1=top[u],f2=top[v];
        while(f1!=f2)
        {
            if(dep[f1]<dep[f2])
                swap(f1,f2),swap(u,v);
            update1(w[f1],w[u],c);
            u=fa[f1];
            f1=top[u];
        }
        if(dep[u]>dep[v])swap(u,v);
        update1(w[u],w[v],c);
    }
    
    inline void upd2(int u,int v,int c){
        int f1=top[u],f2=top[v];
        while(f1!=f2)
        {
            if(dep[f1]<dep[f2])
                swap(f1,f2),swap(u,v);
            update2(w[f1],w[u],c);
            u=fa[f1];
            f1=top[u];
        }
        if(u==v)return;
        if(dep[u]>dep[v])swap(u,v);
        update2(w[son[u]],w[v],c);
    }
    
    int a[Vmax],b[Vmax];
    ll ans1[Vmax],ans2[Vmax];
    void work(int n,int m)
    {
        memset(siz, 0, sizeof(siz));
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        init();
        int root=1;
        fa[root]=nodenum=dep[root]=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            add_(a[i],b[i]);
            add_(b[i],a[i]);
        }
        dfs(root);
        build_tree(root,root);
        char op[10];
        int u,v,c;
        for (int i=1; i<=m; i++) {
            scanf("%s%d%d%d",op,&u,&v,&c);
            if (op[3]=='1')
                upd1(u, v, c);
            else
                upd2(u, v, c);
        }
        for (int i=1; i<=n; i++) {
            ans1[i] = ans1[i-1] + sum1[i];
            ans2[i] = ans2[i-1] + sum2[i];
        }
        for (int i=1; i<=n; i++) {
            printf("%lld",ans1[w[i]]);
            if (i!=n) printf(" ");
        }
        puts("");
        for (int i=1; i<n; i++) {
            int u=a[i],v=b[i];
            if (dep[u] > dep[v]) swap(u, v);
            printf("%lld",ans2[w[v]]);
            if (i!=n-1) printf(" ");
        }
        puts("");
    }
}
using namespace poufen;
int main(){
    int T,cas=1;
    scanf("%d",&T);
    while (T--) {
        int n,m;
        printf("Case #%d:\n",cas++);
        scanf("%d%d",&n,&m);
        work(n, m);
    }
    return 0;
}