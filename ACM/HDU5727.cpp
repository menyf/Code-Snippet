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
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("1005.in","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=10+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int mp[maxn][maxn];
int in_boy[maxn],boy[maxn];
int n,m,x,y,ans;

const int MAXN=15;
int uN,vN;  //u,v数目
int g[MAXN][MAXN];//编号是1~n的
int linker[MAXN];
bool used[MAXN];
bool dfs(int u)
{
    int v;
    for(v=1;v<=vN;v++)
        if(g[u][v]&&!used[v])
        {
            used[v]=true;
            if(linker[v]==-1||dfs(linker[v]))
            {
                linker[v]=u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));
    for(u=1;u<=uN;u++)
    {
        memset(used,0,sizeof(used));
        if(dfs(u))  res++;
    }
    return res;
}

int main(){
    while (scanf("%d%d",&n,&m)!=EOF) {
        memset(mp, 0, sizeof(mp));
        while (m--) {
            scanf("%d%d",&x,&y);
            mp[y][x]=1;
        }
        uN=vN=n;
        ans=n;
        for (int i=1; i<=n; i++) {
            boy[i]=i;
        }
        do {
            memset(g, 1, sizeof(g));
            for (int i=2; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if (mp[boy[i]][j]||mp[boy[i-1]][j]) {
                        g[i][j]=0;
                    }
                }
            }
            for (int i=1; i<=n; i++) {
                if (mp[boy[1]][i]||mp[boy[n]][i]) {
                    g[1][i]=0;
                }
            }
            ans = min(ans, n - hungary());
        } while (next_permutation(boy+2, boy+1+n)&&ans);
        printf("%d\n",ans);
    }
    return 0;
}
