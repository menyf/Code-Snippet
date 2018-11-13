// Wrote by MenYifan on 2016-07-31 22:35:07
// Exe.Time 3750ms Exe.Memory 8560K
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
#include <deque>
#include <algorithm>
#define Memset(a,val) memset(a,val,sizeof(a))
#define PI acos(-1)
#define PB push_back
#define MP make_pair
#define rt(n)       (i == n ? '\n' : ' ')
#define hi         printf("Hi----------\n")
#define IN freopen("input.txt","r",stdin);
#define OUT freopen("output.txt","w",stdout);
#define debug(x) cout<<"Debug : ---"<<x<<"---"<<endl;
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
const int MAXN=1000;
int uN,vN;  //u,v??
double g[MAXN][MAXN];//???0~n-1?
int linker[MAXN];
bool used[MAXN];
struct Point {
    double x, y;
    void in(){
        scanf("%lf%lf",&x,&y);
    }
}rat[MAXN],hole[MAXN];
double dis(Point x,Point y){
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
    
}
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
    int n,m,tmp,now;
    while (scanf("%d",&n)!=EOF) {
        Memset(g, 0);
        uN=n;
        vN=n;
        for (int i=1; i<=n; i++) {
            scanf("%d: (%d) ",&now,&m);
            for (int j=0; j<m; j++) {
                scanf("%d",&tmp);
                g[now+1][tmp+1]=1;
//                vN=max(vN, tmp+1);
            }
        }
        cout<<n-hungary()/2<<endl;
    }
    return 0;
}