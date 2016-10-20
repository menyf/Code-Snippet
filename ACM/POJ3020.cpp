// Wrote by MenYifan on 2016-07-31 15:42:41
// Exe.Time 32ms Exe.Memory 8560K
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
int g[MAXN][MAXN];//???0~n-1?
int mp[MAXN][MAXN];
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
int mx[]={0,0,1,-1};
int my[] = {1,-1,0,0};
int main(){
    char ch;
    int t,n,m;
    scanf("%d",&t);
    while (t--) {
        Memset(mp, 0);
        Memset(g, 0);
        scanf("%d%d",&n,&m);
        int cnt=0;
        for (int i=1; i<=n; i++) {
            scanf("%*c");
            for (int j=1; j<=m; j++) {
                scanf("%c",&ch);
                if (ch=='*') {
                    mp[i][j]=++cnt;
                }
            }
        }
        uN=vN=cnt;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (mp[i][j]) {
                    for (int k=0; k<4; k++) {
                        int tx = i+mx[k];
                        int ty = j+my[k];
                        if (mp[tx][ty]) {
                            g[mp[i][j]][mp[tx][ty]]=1;
                        }
                    }
                }
            }
        }
        cout<<cnt-hungary()/2<<endl;
    }
}