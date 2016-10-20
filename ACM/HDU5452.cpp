// Wrote by MenYifan on 2016-08-27 16:13:38
// Exe.Time 1497ms Exe.Memory 3620K
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
const int maxn=20000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int n , m , pre[maxn] ,rt[maxn], ecnt,cnt[maxn],cnt2[maxn],ans,sb[maxn];
bool vis[maxn];
struct edge
{
    int v , next;
} e[maxn *20];

int dep[maxn] , f[17][maxn] , Lev , s[maxn];///1<<16 < N, f[j][i] ??i??2^j???

void dfs(int x , int fa)///????bfs??bfs??????????
{
    dep[x] = dep[fa] + 1;
    f[0][x] = fa , s[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].v;
        if (y != fa)
        {
            dfs(y , x);
            s[x] += s[y];///??x?????
        }
    }
}
void bfs(int rt)///???????????????
{
    queue<int> q;
    q.push(rt);
    f[0][rt] = 0,dep[rt] = 1,vis[rt] = 1;
    while(!q.empty())
    {
        int fa = q.front();
        q.pop();
        for (int i = pre[fa] ; ~i ; i = e[i].next)
        {
            int x = e[i].v;
            if (!vis[x])
            {
                dep[x] = dep[fa] + 1;
                f[0][x] = fa ,vis[x] = 1;
                q.push(x);
            }
        }
    }
}
int LCA(int x , int y)
{
    if (dep[x] > dep[y]) swap(x , y);
    for (int i = Lev ; i >= 0 ; -- i)///?y??dep[y] - dep[x]???
        if (dep[y] - dep[x] >> i & 1)
            y = f[i][y];
    if (x == y) return y;
    for (int i = Lev ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y])
            x = f[i][x] , y = f[i][y];
    return f[0][x];
}
int get_kth_anc(int x , int k) ///?x??k???
{
    for (int i = 0 ; i <= Lev ; ++ i)
        if (k >> i & 1)
            x = f[i][x];
    return x;
}
void init()
{
    memset(pre , -1 , sizeof(pre));
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
    memset(rt,0,sizeof(rt));
    ecnt = 0;
}
void addedge(int x,int y)
{
    e[ecnt].v = y,
    e[ecnt].next = pre[x],
    pre[x] = ecnt ++;
}
int getLCA(int x,int y){
    if (dep[x] < dep[y])
        swap(x , y);
    return LCA(x , y);
}
void fuck(int rt,int fa){
    sb[rt] = cnt[rt]+1;
    for (int i=pre[rt]; i!=-1; i=e[i].next) {
        int v = e[i].v;
        if (v!=fa) {
            fuck(v, rt);
//            debug2(v, sb[v]);
            sb[rt] += sb[v];
//            debug2(rt, sb[rt]);
        }
    }
//    printf("rt:%d val:%d cnt2:%d\n",rt,sb[rt],cnt2[rt]);
    sb[rt] -= cnt2[rt];
    ans = min(ans, sb[rt]);
//    debug2(rt, sb[rt]);
}
void work()
{
    int i , j , x , y , z,anc;
    init();
    scanf("%d%d",&n,&m);
    for (i = 1 ; i < n ; ++ i)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
        rt[y]  =x;
    }
    for(int i=1; i<=n; i++)
    {
        if(rt[i]==0)
        {
            anc = i;    //???????
            break;
        }
    }
    dfs(anc , 0);
    for (j = 1 ; 1 << j < n ; ++ j)
        for (i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
    Lev = j - 1;
    
    int u,v;
    for (int i=1; i<= m-n+1; i++) {
        scanf("%d%d",&u,&v);
        cnt[u]++;
        cnt[v]++;
        int lca = getLCA(u, v);
        cnt2[lca] += 2;
    }
    ans = INF;
    fuck(anc, -1);
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        work();
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
/*
 100
 8 13
 1 2
 1 5
 2 3
 2 4
 5 6
 6 7
 6 8
 3 7
 2 7
 4 7
 5 8
 4 8
 3 5
*/
