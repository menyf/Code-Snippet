// Wrote by MenYifan on 2016-07-25 15:15:53
// Exe.Time 405ms Exe.Memory 14560K
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
#define pb push_back
#define mp make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=100000+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int N = 100005;

int n , m , pre[N] ,rt[N], mcnt;
bool vis[N];
struct edge
{
    int x , next;
} e[N << 1];

int dep[N] , f[17][N] , Lev , s[N];///1<<16 < N, f[j][i] ??i??2^j???

void dfs(int x , int fa)///????bfs??bfs??????????
{
    dep[x] = dep[fa] + 1;
    f[0][x] = fa , s[x] = 1;
    for (int i = pre[x] ; ~i ; i = e[i].next)
    {
        int y = e[i].x;
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
    memset(rt,0,sizeof(rt));
    mcnt = 0;
}
void addedge(int x,int y)
{
    e[mcnt].x = y,
    e[mcnt].next = pre[x],
    pre[x] = mcnt ++;
}
int main()
{
    while (scanf("%d",&n)!=EOF) {
        int i , j , x , y , z,anc;
        init();
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
                anc = i;
                break;
            }
        }
        dfs(anc , 0);
        for (j = 1 ; 1 << j < n ; ++ j)
            for (i = 1 ; i <= n ; ++ i)
                f[j][i] = f[j - 1][f[j - 1][i]];
        Lev = j - 1;
//        hi;
        int k;
        scanf("%d",&k);
        while (k--) {
            scanf("%d%d",&x,&y);
            if (dep[x] < dep[y])
                swap(x , y);
            if (x==y) {
                cout<<n<<endl;
            }
            else if ((dep[x]-dep[y])%2){
                cout<<0<<endl;
            }
            else if (dep[x]==dep[y]){
                int lca = LCA(x, y);
                int xx = get_kth_anc(x, dep[x]-dep[lca]-1);
                int yy = get_kth_anc(y, dep[y]-dep[lca]-1);
                cout<<n-s[xx]-s[yy]<<endl;
            }
            else{
                int dis = dep[x] + dep[y] - dep[LCA(x, y)]*2;
                int mid = get_kth_anc(x, dis/2);
                int xx = get_kth_anc(x, dis/2-1);
                cout<<s[mid]-s[xx]<<endl;
            }
        }
    }
    
    return 0;
}