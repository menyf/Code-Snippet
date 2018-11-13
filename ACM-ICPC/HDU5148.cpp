// Wrote by MenYifan on 2016-08-10 21:34:34
// Exe.Time 421ms Exe.Memory 2516K
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
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
const int maxn=2005+5;
const int mod=1000000007;
const int INF=0x3f3f3f3f;
const double eps=1e-8;
int he[2005],ecnt,n,k;
ll dp[maxn][55];

struct Edge{
    int v,w,next;
}e[4005];
void adde(int u,int v,int w){
    e[ecnt].v=v;
    e[ecnt].w =w ;
    e[ecnt].next = he[u];
    he[u] = ecnt++;
}
void init(){
    Memset(he, -1);
    ecnt = 0;
    Memset(dp, 0x3f);
}
void dfs(int u,int pre,int k){
    dp[u][0] = 0;
    dp[u][1] = 0;
    for (int i=he[u]; ~i; i = e[i].next) {
        int v = e[i].v;
        if (v == pre) continue;
        dfs(v, u, k);
        for (int j=k; j>=0; j--) {
            for (int l =1; l<=j; l++) {
                dp[u][j]=min(dp[u][j], dp[u][j-l]+dp[v][l]+e[i].w*l*(k-l)*2);
            }
        }
    }

}
int main(){
    int T,x,y,tmp;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&k);
        init();
        for (int i=1; i<n; i++) {
            scanf("%d%d%d",&x,&y,&tmp);
            adde(x, y, tmp);
            adde(y, x, tmp);
        }
        dfs(1,0,k);
        cout<<dp[1][k]<<endl;
    }
}