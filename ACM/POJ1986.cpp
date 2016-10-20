#pragma comment(linker, "/STACK:10240000000,10240000000")///扩栈，要用c++交，用g++交并没有什么卵用。。。
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ctype.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-8
#define INF 0x7fffffff
#define maxn 100005
#define PI acos(-1.0)
using namespace std;
typedef long long LL;
const int N = 100005;
const int inf=0x3f3f3f3f;
int n , m , pre[N] ,rt[N], mcnt;
bool vis[N];
struct edge
{
    int x/*指向子节点*/ , next/*指向前一条边*/, w;
} e[N << 1];

int dep[N] , f[17][N] , Lev , s[N], dist[N];///1<<16 < N, f[j][i] 表示i的第2^j个祖先

void dfs(int x , int fa)///也可以用bfs，但bfs不能统计节点孩子个数
{
    dep[x] = dep[fa] + 1;
    f[0][x] = fa;
    s[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].x;
        if (y != fa)
        {
            dist[y]=dist[x]+e[i].w;
            dfs(y , x);
            s[x] += s[y];///节点x的孩子个数
        }
    }
}
void bfs(int rt)///不需要求孩子个数，同时防止暴栈
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
            int x = e[i].x;
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
    for (int i = Lev ; i >= 0 ; -- i)///找y的第dep[y] - dep[x]个祖先
        if (dep[y] - dep[x] >> i & 1)
            y = f[i][y];
    if (x == y) return y;
    for (int i = Lev ; i >= 0 ; -- i)
        if (f[i][x] != f[i][y])
            x = f[i][x] , y = f[i][y];
    return f[0][x];
}
int get_kth_anc(int x , int k) ///找x的第k个祖先
{
    for (int i = 0 ; i <= Lev ; ++ i)
        if (k >> i & 1)
            x = f[i][x];
    return x;
}
void init()
{
    memset(pre , -1 , sizeof(pre));
    memset(rt,0,sizeof(rt));
    memset(dist, inf, sizeof(dist));
    mcnt = 0;
}
void addedge(int x,int y, int z)
{
    e[mcnt].x = y,
    e[mcnt].next = pre[x],
    e[mcnt].w=z;
    pre[x] = mcnt ++;///与x相连的边数
}
void work()
{
    int j, x , y , z,anc;
    char c;
    init();
    for (int i = 1 ; i <=m ; ++i)
    {
        scanf("%d %d %d %c", &x, &y, &z, &c);
        addedge(x, y, z);
        addedge(y, x, z);
        rt[y]  =x;
    }
    for(int i=1; i<=n; ++i)
    {
        if(rt[i]==0)
        {
            anc = i;
            break;
        }
    }
    dfs(anc , 0);
    for (j = 1 ; 1 << j < n ; ++ j)
        for (int i = 1 ; i <= n ; ++ i)
            f[j][i] = f[j - 1][f[j - 1][i]];
    Lev = j - 1;
    int num;
    scanf("%d", &num);
    int p, q;
    while(num--)
    {
        scanf("%d%d", &p, &q);
        printf("%d\n", dist[p]+dist[q]-2*dist[LCA(p, q)]);
    }
}
int main()
{
    char str;
    while(~scanf("%d%d", &n, &m))
    {
        work();
    }
    return 0;
}
