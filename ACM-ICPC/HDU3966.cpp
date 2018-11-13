// Wrote by MenYifan on 2016-08-20 14:52:23
// Exe.Time 2230ms Exe.Memory 11120K
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
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int Vmax = 5*1e4 + 5;//????
const int Emax =2*1e5+5;//???? ??Vmax???
namespace segment_tree{
    int sum[Vmax<<2],add[Vmax<<2];
    void PushUp(int rt)
    {
        sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    }
    void PushDown(int rt,int m)
    {
        if (add[rt])
        {
            add[rt<<1] += add[rt];
            add[rt<<1|1] += add[rt];
            sum[rt<<1] += add[rt] * (m - (m >> 1));
            sum[rt<<1|1] += add[rt] * (m >> 1);
            add[rt] = 0;
        }
    }
    void build(int l,int r,int rt=1)
    {
        add[rt] = 0;
        if (l == r)
        {
            sum[rt]=0;
            return ;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        PushUp(rt);
    }
    void update(int L,int R,int c,int l,int r,int rt=1)
    {
        if (L <= l && r <= R)
        {
            add[rt] += c;
            sum[rt] += c * (r - l + 1);
            return ;
        }
        PushDown(rt , r - l + 1);
        int m = (l + r) >> 1;
        if (L <= m) update(L , R , c , lson);
        if (m < R) update(L , R , c , rson);
        PushUp(rt);
    }
    int query(int L,int R,int l,int r,int rt=1)
    {
        if (L <= l && r <= R)
        {
            return sum[rt];
        }
        PushDown(rt , r - l + 1);
        int m = (l + r) >> 1;
        int ret = 0;
        if (L <= m) ret += query(L , R , lson);
        if (m < R) ret += query(L , R , rson);
        return ret;
    }
}
namespace poufen{
    using namespace segment_tree;
    int siz[Vmax],son[Vmax],fa[Vmax],dep[Vmax],top[Vmax],w[Vmax];
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
    
     int find(int u,int v){
        int ret=0;
        int f1=top[u],f2=top[v];
        while(f1!=f2)
        {
            if(dep[f1]<dep[f2])
                swap(f1,f2),swap(u,v);
            ret+=query(w[f1],w[u],1,nodenum);
            u=fa[f1];
            f1=top[u];
        }
        if(dep[u]>dep[v])swap(u,v);
        ret+=query(w[u],w[v],1,nodenum);
        return ret;
    }
    inline void upd(int u,int v,int c){
        int f1=top[u],f2=top[v];
        while(f1!=f2)
        {
            if(dep[f1]<dep[f2])
                swap(f1,f2),swap(u,v);
            update(w[f1],w[u],c,1,nodenum);
            u=fa[f1];
            f1=top[u];
        }
        if(dep[u]>dep[v])swap(u,v);
        update(w[u],w[v],c,1,nodenum);
    }
    
    int a[Vmax],b[Vmax];
    int val[Vmax];//
    
}
using namespace poufen;
int main(){
    int n,m,p,x,y,tmp;
    while (scanf("%d%d%d",&n,&m,&p)!=EOF) {
        memset(siz, 0, sizeof(siz));
        memset(sum, 0, sizeof(sum));
        
        init();
        int root=1;
        fa[root]=nodenum=dep[root]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&val[i]);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            add_(a[i],b[i]);
            add_(b[i],a[i]);
        }
        dfs(root);
        build_tree(root,root);
        
        build(1, nodenum);
        
        for(int i=1;i<=n;i++)
            update(w[i], w[i], val[i], 1, nodenum);
        
        for (int cas = 1 ; cas <= p ; cas++) {
            char s[2];
            scanf("%s",s);
            if (s[0]=='Q') {
                scanf("%d",&x);
                cout<<find(x, x)<<endl;
            }
            else if (s[0]=='I'){
                scanf("%d%d%d",&x,&y,&tmp);
                upd(x, y, tmp);
//                hi;
            }
            else if (s[0]=='D'){
                scanf("%d%d%d",&x,&y,&tmp);
                upd(x, y, -tmp);
            }
        }
    }
}